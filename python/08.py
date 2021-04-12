# Day 8: Memory Maneuver

from santas_little_helpers import *
from collections import deque


input_file = deque(int(num) for num in get_input('inputs/08.txt', ' '))


def dfs(input_stream, metadata=0):
    children_count = input_stream.popleft()
    metadata_count = input_stream.popleft()
    # base condition: single child
    if children_count == 0:
        metadata += sum(input_stream.popleft() for _ in range(metadata_count))
        # return reduced input stream
        return input_stream, metadata
    else:
        for child in range(children_count):
            rest, metadata = dfs(input_stream, metadata)
        # once we clear all the children, we need to append the metadata of the parent:
        rest.appendleft(metadata_count)
        rest.appendleft(0)
        return dfs(rest, metadata)



_, part_1 = dfs(input_file)

print_solutions(part_1)
# Part 1 solution is: 46962
