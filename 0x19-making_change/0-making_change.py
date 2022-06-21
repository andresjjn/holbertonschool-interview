#!/usr/bin/python3
"""Making change module"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest
    number of coins needed to meet a given amount total"""
    if total <= 0:
        return 0
    aux = total + 1
    dc = {0: 0}
    for i in range(1, total + 1):
        dc[i] = aux
        for item in coins:
            x = i - item
            if x < 0:
                continue
            dc[i] = min(dc[x] + 1, dc[i])
    if dc[total] == total + 1:
        return -1
    return dc[total]
