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

part_1 = sleepiest_guard * sleepiest_minute
print_solutions(part_1)
