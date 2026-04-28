from collections import deque


def water_jug(cap_x, cap_y, target):
    visited = {(0, 0)}
    queue = deque([(0, 0)])
    parent = {(0, 0): None}

    while queue:
        x, y = queue.popleft()
        if x == target or y == target:
            path = []
            state = (x, y)
            while state is not None:
                path.append(state)
                state = parent[state]
            return path[::-1]

        for nx, ny in [
            (cap_x, y), (x, cap_y),
            (0, y), (x, 0),
            (max(0, x+y-cap_y), min(cap_y, x+y)),
            (min(cap_x, x+y), max(0, x+y-cap_x))
        ]:
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                parent[(nx, ny)] = (x, y)
                queue.append((nx, ny))
    return None


path = water_jug(4, 3, 2)
print("Steps to measure 2 litres (4L jug, 3L jug):")
if path is None:
    print("No solution found.")
else:
    for i, step in enumerate(path):
        print(f"  Step {i}: Jug-4 = {step[0]}L  |  Jug-3 = {step[1]}L")
