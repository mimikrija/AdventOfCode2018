# Day 2: Inventory Management System

from santas_little_helpers import *
from collections import Counter

def appearing_exactly(word, times):
    if times in Counter(word).values():
        return True
    return False

words = get_input('inputs/02.txt')

two, three = (sum(appearing_exactly(word, count) for word in words) for count in {2,3})
checksum = two * three

print_solutions(checksum)
