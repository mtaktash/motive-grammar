import pip
import argparse
import re
import glob


def install(package):
	pip.main(['install', package])


def prepare_string(a):
	t = a.replace('\t', '').replace('\n', '')\
		.replace('\xa0', '').replace(' ,', '').replace(' .', '').replace(' ?', '')\
		.replace(' !', '').replace(' :', '').replace(' (', '').replace(' )', '')\
		.lower().translate(str.maketrans('', '', '–—.,?!()…«»:;')).strip()
	return re.sub(' +', ' ', t)


if __name__ == '__main__':
	install('tqdm')
	install('lxml')
	install('beautifulsoup4')
	install('pandas')
	from tqdm import tqdm
	from bs4 import BeautifulSoup
	import pandas as pd
	parser = argparse.ArgumentParser()
	parser.add_argument(
		'--folder',
	)
	parser.add_argument(
		'-o', '--output'
	)
	args = parser.parse_args()
	with open(args.output, 'r') as output:
		file_str = ''.join(output.readlines())
		soup = BeautifulSoup(file_str, 'lxml')
	motifs = [prepare_string(soup.select_one('a[name="{}"]'.format(tag['href'][1:])).text)[:-4] for tag in tqdm(soup.select('td > a'))]
	data = list()
	for filename in glob.glob('{}/*.txt'.format(args.folder)):
		q = 0
		with open(filename) as file:
			text = prepare_string(file.read())
			for motif in motifs:
				if motif in text:
					q += 1
			data.append({
				'text': int(filename[len(args.folder)+1:filename.find('.txt')]),
				'q': q,
			})
	df = pd.DataFrame(data)
	df = df[['text', 'q']].sort('text')
	df.to_csv('table.tsv', sep='\t', index=False)
