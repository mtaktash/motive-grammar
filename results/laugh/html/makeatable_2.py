import pip
import argparse
import re
import glob

from tqdm import tqdm
from bs4 import BeautifulSoup
import pandas as pd


def prepare_string(a):
	t = a.replace('\t', '').replace('\n', '')\
		.replace('\xa0', '').replace(' ,', '').replace(' .', '').replace(' ?', '')\
		.replace(' !', '').replace(' :', '').replace(' (', '').replace(' )', '')\
		.lower().translate(str.maketrans('', '', '–—.,?!()…«»:;')).strip()
	return re.sub(' +', ' ', t)


if __name__ == '__main__':
	parser = argparse.ArgumentParser()
	parser.add_argument(
		'-f', '--folder',
	)
	parser.add_argument(
		'-o', '--output'
	)
	args = parser.parse_args()
	with open(args.output, 'r') as output:
		file_str = ''.join(output.readlines()).replace('</html>', '') + '</html>'
		soup = BeautifulSoup(file_str, 'lxml')
	motifs = [prepare_string(soup.select_one('a[name="{}"]'.format(tag['href'][1:])).text)[:-4] for tag in tqdm(soup.select('td > a'))]
	data = list()
	data2 = list()
	for filename in glob.glob('{}/*.txt'.format(args.folder)):
		q = 0
		with open(filename) as file:
			text = prepare_string(''.join(file.readlines()))
			for motif in motifs:
				if motif in text:
					q += 1
					data2.append({
						'text': int(filename[len(args.folder)+1:filename.find('.txt')]),
						'motif': motif,
					})
			data.append({
				'text': int(filename[len(args.folder)+1:filename.find('.txt')]),
				'q': q,
			})
	df = pd.DataFrame(data)
	df = df[['text', 'q']].sort_values(by='text')
	df.to_csv('table.tsv', sep='\t', index=False)
	df2 = pd.DataFrame(data2)
	df2 = df2[['text', 'motif']].sort_values(by='text')
	df2.to_csv('table2.tsv', sep='\t', index=False)
