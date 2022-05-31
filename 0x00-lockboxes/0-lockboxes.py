#!/usr/bin/python3
"""Lockboxes Module"""


def canUnlockAll(boxes):
    """boxes"""

    stat = False
    k = [0]
    indexes = []
    sizes = len(boxes)

    for i in range(sizes):
        indexes.append(i)

    while len(indexes):
        arr_aux = []
        for key in k:
            if key in indexes:
                stat = True
                for box in boxes[key]:
                    if box in indexes and box not in k:
                        arr_aux.append(box)
                indexes.remove(key)
        k.extend(arr_aux)

        if not stat:
            return False
        stat = False
    return True
