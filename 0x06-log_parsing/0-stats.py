#!/usr/bin/python3
"""Log parsing"""
from sys import stdin

ttl = 0

stts_dic = {
    "200": 0,
    "301": 0,
    "400": 0, "401": 0, "403": 0, "404": 0, "405": 0,
    "500": 0
}

lns = 0

try:

    for idx in stdin:

        rslt_data = idx.split(' ')

        if len(rslt_data) > 6:
            stts, sz = rslt_data[-2:]
            ttl += int(sz)
            if stts in stts_dic:
                stts_dic[stts] += 1
            lns += 1

        if lns == 10:
            print('File size: {}'.format(ttl))
            for (cd, contr) in sorted(stts_dic.items()):
                if contr > 0:
                    print('{}: {}'.format(cd, contr))
                lns = 0

finally:
    print('File size: {}'.format(ttl))
    for (cd, contr) in sorted(stts_dic.items()):
        if contr > 0:
            print('{}: {}'.format(cd, contr))
