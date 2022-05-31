#!/usr/bin/python3
"""Min op"""


def minOperations(n):
    """Min Op"""

    if n <= 1:
        return 0
    if type(n) != int:
        return 0

    anD = 1
    cpie = 1
    acm = 1

    while anD < n:
        if anD != cpie and n % anD == 0:
            cpie = anD
            acm += 1
        anD += cpie
        acm += 1

    if anD == n:
        return acm
    return 0
