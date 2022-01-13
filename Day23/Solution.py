import sys
from functools import cache

grid = {}
final_grid = {(3, 2): 'A', (3, 3): 'A', (5, 2): 'B', (5, 3): 'B', (7, 2): 'C', (7, 3): 'C', (9, 2): 'D', (9, 3): 'D'}
points = {'A': 1, 'B': 10, 'C': 100, 'D': 1000}

for y, line in enumerate(sys.stdin):
    for x, c in enumerate(line.rstrip()):
        if c == '#' or c == ' ':
            continue
        if c == '.':
            c = ''
        grid[x, y] = c


def is_solved(grid):
    return (grid | final_grid) == grid


def can_move(grid, c, x, y):
    key = x, y
    t = grid.get(key, 'X')
    if t != ' ':
        return False
    if key in final_grid and final_grid[key] != c:
        return False
    return True


def serialize(grid):
    return frozenset((x, y, c) for (x, y), c in grid.items())


def unserialize(sgrid):
    return {(x, y): c for x, y, c in sgrid}


@cache
def solution(sgrid):
    grid = unserialize(sgrid)
    if is_solved(grid):
        return 0

    for (x, y), c in grid.items():
        if not c:
            continue
        for dx, dy in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nx, ny = x+dx, y+dy
            if can_move(grid, c, nx, ny):
                print('?')


print(solution(serialize(grid)))