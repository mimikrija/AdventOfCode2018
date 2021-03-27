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


def remove_type(in_molecule, type_ord):
    removed = ''.join(c for c in in_molecule if ord(c) != type_ord and ord(c) != type_ord + 32)
    return deque(removed)


def find_shortest_reduction(in_molecule):
    return min(reduce_molecule(remove_type(in_molecule, type_ord)) for type_ord in range(ord('A'), ord('Z')+1))


original_molecule = deque(get_input('inputs/05.txt')[0])

print_solutions(reduce_molecule(original_molecule), find_shortest_reduction(original_molecule))
# Part 1 solution is: 11118
# Part 2 solution is: 6948
