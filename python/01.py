# Day 1: Chronal Calibration

from santas_little_helpers import *

# since there are '+' signs in the input, map(int, num) does not work!
frequency_diffs = [int(num) for num in get_input('inputs/01.txt')]

frequency = sum(frequency_diffs)


def first_reached_twice(in_diffs):
    unique_frequencies = set()
    frequency = 0
    while True:
        for diff in in_diffs:
            unique_frequencies.add(frequency)
            frequency += diff
            if frequency in unique_frequencies:
                return frequency



print_solutions(frequency, first_reached_twice(frequency_diffs))
# Part 1 solution is: 580
# Part 2 solution is: 81972
