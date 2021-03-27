# Day 5: Alchemical Reduction

from santas_little_helpers import *
from collections import deque


def is_reducable(left, right):
    return abs(ord(left) - ord(right)) == 32


def reduce_molecule(in_molecule):
    rest = deque(in_molecule)
    reduced = deque(rest.popleft())
    while rest:
        if reduced:
            left = reduced.pop()
        else:
            left = rest.popleft()
        right = rest.popleft()
        if not is_reducable(left, right):
            reduced.append(left)
            reduced.append(right)
    return len(reduced)



original_molecule = deque(get_input('inputs/05.txt')[0])

print_solutions(reduce_molecule(original_molecule))
