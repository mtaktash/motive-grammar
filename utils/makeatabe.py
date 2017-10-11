# -*- codind: utf-8 -*-
import codecs
import os
f = codecs.open('PrettyOutput.html', 'r', 'utf-8')
lines = f.readlines()
arr = [0 for i in range(1064)]
results = []
i = 0
for line in lines:
    if 'table' in line:
        try:
            if 'href' in lines[i + 6]:
                results.append((lines[i + 6][21:-10]).replace(' ,', ','))
        except IndexError:
            pass
    i += 1


print(results)
for fil in os.listdir('./2206'):
    f1 = codecs.open('./2206/' + fil, 'r', 'utf-8')
    ft = f1.read()
    for res in results:
        if res in ft:
            arr[int(fil[:-4]) - 1] += 1
#            print(res, fil)
    f1.close()


ct = codecs.open('table_1.tsv', 'w', 'utf-8')
for el in range(len(arr)):
    ct.write(str(el) + '\t' + str(arr[el]) + '\r\n')

ct.close()