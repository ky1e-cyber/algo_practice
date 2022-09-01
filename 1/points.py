'''
По данным n отрезкам необходимо найти множество точек минимального размера, для которого каждый из отрезков содержит хотя бы одну из точек.

В первой строке дано число 1 ≤ n ≤ 100 отрезков. 
Каждая из последующих n строк содержит по два числа 0 ≤l ≤ r ≤ 10**9, задающих начало и конец отрезка. 
Выведите оптимальное число m точек и сами m точек. Если таких множеств точек несколько, выведите любое из них.
'''

from typing import List, Set

n: int = int(input())
segments: List[List[int]] = [list(map(int, input().split())) for _ in range(n)]

segments.sort(key = lambda s: s[0])

points_set: Set[int] = set()

i: int = 0
point: int = segments[0][0]
end: int = segments[0][1]

while i < n:
    if segments[i][0] <= end:
        end = min(end, segments[i][1])
    else:
        points_set.add(point)
        end = segments[i][1]
    point = segments[i][0]
    i += 1
    
points_set.add(point)

print(f"{len(points_set)}\n" + " ".join([str(x) for x in points_set]))