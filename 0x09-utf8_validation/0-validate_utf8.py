#!/usr/bin/python3
"""module"""


def validUTF8(data):
    """a"""
    ntyp = 0
    for dec_n in data:
        bbyt = format(dec_n, '#010b')[-8:]
        if ntyp == 0:
            for bit in bbyt:
                if bit == '0':
                    break
                ntyp += 1
            if ntyp == 0:
                continue
            if ntyp == 1 or ntyp > 4:
                return False
        else:
            if not (bbyt[0] == '1' and bbyt[1] == '0'):
                return False
        ntyp -= 1
    return ntyp == 0
