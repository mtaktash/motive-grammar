#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  11.10.2017 13:47:07 MSK

import sys

def main(argv):
    f = open(argv, 'r', encoding='utf-8')
    wordlist = []
    for line in f:
        line = line.strip()
        if line:
            wordlist.append(line)
    gram_string = "' | '".join(wordlist) + ';'
    f.close()
    fw = open('output_string.txt', 'w', encoding="utf-8")
    fw.write(gram_string)
    fw.close()
    
    return 0

if __name__ == '__main__':
    main(sys.argv[1])
