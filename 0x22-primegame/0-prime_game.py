#!/usr/bin/python3
"""Prime game"""


def isWinner(x, nums):
    """Prime game"""
    if not nums or x < 1:
        return None
    mnu = max(nums)
    pval = 0.5
    nbr = [True for _ in range(max(mnu + 1, 2))]
    for idx in range(2, int(pow(mnu, pval)) + 1):
        if not nbr[idx]:
            continue
        for val in range(idx*idx, mnu + 1, idx):
            nbr[val] = False
    nbr[0] = nbr[1] = False
    ct = 0
    for idx in range(len(nbr)):
        if nbr[idx]:
            ct += 1
        nbr[idx] = ct
    p1 = 0
    for num in nums:
        p1 += nbr[num] % 2 == 1
    if p1 * 2 == len(nums):
        return None
    if p1 * 2 > len(nums):
        return "Maria"
    return "Ben"
