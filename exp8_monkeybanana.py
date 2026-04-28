from collections import deque

# State: (monkey_pos, box_pos, on_box, has_banana)
# Positions: 'door', 'window', 'middle'

def monkey_banana():
    start = ('door', 'window', False, False)
    goal  = ('middle', 'middle', True, True)

    queue = deque([(start, [start])])
    visited = {start}

    def get_moves(state):
        mp, bp, ob, hb = state
        results = []
        if not ob:
            for pos in ['door', 'window', 'middle']:
                if pos != mp:
                    results.append((pos, bp, False, hb))   # walk
            if mp == bp:
                results.append((mp, bp, True, hb))         # climb box
        else:
            if mp != 'middle':
                results.append(('middle', 'middle', True, hb))  # push box to middle
            elif not hb:
                results.append((mp, bp, ob, True))          # grab banana
        return results

    while queue:
        state, path = queue.popleft()
        if state == goal:
            return path
        for ns in get_moves(state):
            if ns not in visited:
                visited.add(ns)
                queue.append((ns, path + [ns]))

path = monkey_banana()
print("Monkey Banana Problem - Solution Path:")
print("State: (monkey_pos, box_pos, on_box, has_banana)\n")
for i, s in enumerate(path):
    print(f"  Step {i}: {s}")
