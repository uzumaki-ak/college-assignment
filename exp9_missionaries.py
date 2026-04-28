from collections import deque

# State: (missionaries_left, cannibals_left, boat_side)
# boat_side: 1 = left bank, 0 = right bank

def is_valid(m, c):
    if m < 0 or c < 0 or m > 3 or c > 3:
        return False
    if m > 0 and m < c:           # left bank unsafe
        return False
    if (3-m) > 0 and (3-m) < (3-c):  # right bank unsafe
        return False
    return True

def solve():
    start = (3, 3, 1)
    goal  = (0, 0, 0)
    queue = deque([(start, [start])])
    visited = {start}

    moves = [(1,0),(2,0),(0,1),(0,2),(1,1)]
    while queue:
        (m, c, b), path = queue.popleft()
        if (m, c, b) == goal:
            return path
        for dm, dc in moves:
            nm = m - dm if b == 1 else m + dm
            nc = c - dc if b == 1 else c + dc
            ns = (nm, nc, 1 - b)
            if is_valid(nm, nc) and ns not in visited:
                visited.add(ns)
                queue.append((ns, path + [ns]))

path = solve()
print("Missionaries-Cannibals Solution")
print("State: (Missionaries_left, Cannibals_left, Boat_side)\n")
for i, s in enumerate(path):
    side = "LEFT " if s[2] else "RIGHT"
    print(f"  Step {i:2d}: M={s[0]}, C={s[1]}, Boat={side}")
