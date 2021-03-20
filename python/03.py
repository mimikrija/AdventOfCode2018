# Day 3: No Matter How You Slice It

from santas_little_helpers import *
from re import findall


def generate_coordinates(start_x, start_y, range_x, range_y):
    return{(x,y) for x in range(start_x, start_x+range_x)
                 for y in range(start_y, start_y+range_y)}


def overlap(in_patches):
    total_fabric = set()
    overlap = set()
    for patch in patches.values():
        overlap |= total_fabric & patch
        total_fabric |= patch
    return overlap


def not_overlapping(in_patches, in_overlap):
    for ID, patch in in_patches.items():
        if not in_overlap & patch:
            return ID


patches = {}
for line in get_input('inputs/03.txt'):
    patch_ID, start_x, start_y, range_x, range_y = map(int, findall(r'\d+', line))
    patches[patch_ID] = generate_coordinates(start_x, start_y, range_x, range_y)


overlapping = overlap(patches)
overlapping_inches = len(overlapping)
ID_not_overlapping = not_overlapping(patches, overlapping)

print_solutions(overlapping_inches, ID_not_overlapping)
