from santas_little_helpers import *
from re import findall
from collections import Counter


timetable = sorted(get_input('inputs/04.txt'))

guard_sleepy_minutes = {}

for line in timetable:
    data, text = line.split(']')
    year, month, day, hour, minute = map(int, findall(r'\d+', data))
    if 'Guard' in text:
        ID = int(text.split()[1][1:])
        start, end = None, None
    if hour != 0:
        minute = 0
    if 'asleep' in text:
        start = minute
    if 'wakes' in text:
        end = minute
        guard_sleepy_minutes[ID] = guard_sleepy_minutes.get(ID, []) + list(range(start, end))


sleepy_minutes = {ID: len(minutes) for ID, minutes in guard_sleepy_minutes.items()}

sleepiest_guard = max(sleepy_minutes, key=sleepy_minutes.get)
sleepiest_minute = Counter(guard_sleepy_minutes[sleepiest_guard]).most_common(1)[0][0]

minute_frequency = {ID: tuple(reversed(list(Counter(guard_sleepy_minutes[ID]).most_common(1)[0]))) for ID in guard_sleepy_minutes.keys()}
most_frequently_asleep_on_a_minute_guard = max(minute_frequency, key=minute_frequency.get)
most_frequent_minute = minute_frequency[most_frequently_asleep_on_a_minute_guard][1]

strategy_1 = sleepiest_guard * sleepiest_minute
strategy_2 = most_frequently_asleep_on_a_minute_guard * most_frequent_minute

print_solutions(strategy_1, strategy_2)
# Part 1 solution is: 84834
# Part 2 solution is: 53427
