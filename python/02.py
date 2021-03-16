# Day 2: Inventory Management System

from santas_little_helpers import *
from collections import Counter
from itertools import combinations


def appearing_exactly(word, times):
    if times in Counter(word).values():
        return True
    return False


def drop_the_common(first, second):
    return ''.join(one for one, two in zip(first, second) if one == two)


def differing_by_one(in_words):
    for first, second in combinations(in_words, 2):
        common_dropped = drop_the_common(first, second)
        if len(common_dropped) == len(first) - 1:
            return common_dropped


words = get_input('inputs/02.txt')

two, three = (sum(appearing_exactly(word, count) for word in words) for count in {2,3})
checksum = two * three


print_solutions(checksum, differing_by_one(words))
# Part 1 solution is: 8892
# Part 2 solution is: zihwtxagifpbsnwleydukjmqv
