# Day 8: Memory Maneuver

from santas_little_helpers import *
from collections import deque


input_file = deque(int(num) for num in get_input('inputs/08.txt', ' '))


def dfs(input_stream):
    children_count = input_stream.popleft()
    metadata_count = input_stream.popleft()
    total_meta = 0

    # if there's any children keep recursing through the children
    for _ in range(children_count):
        input_stream, metadata_sum = dfs(input_stream)
        total_meta += metadata_sum

    # if we're here it means that there's either no children or we're done with recursing
    # print(children_count, metadata_count, input_stream)
    total_meta += sum(input_stream.popleft() for _ in range(metadata_count))
    return input_stream, total_meta


_, part_1 = dfs(input_file)

print_solutions(part_1)
# Part 1 solution is: 46962
