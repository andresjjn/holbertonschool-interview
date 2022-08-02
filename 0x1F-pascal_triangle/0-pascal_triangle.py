#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """Pascal's Triangle"""
    if n <= 0:
        return []

    triangle = [[1]]

    while len(triangle) != n:
        prev = triangle[-1]
        loc = [1]

        for i in range(len(prev) - 1):
            loc.append(prev[i] + prev[i + 1])

        loc.append(1)
        triangle.append(loc)

    return triangle
