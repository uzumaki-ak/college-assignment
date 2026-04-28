import heapq

goal = (1, 2, 3, 4, 5, 6, 7, 8, 0)

def manhattan(state):
    dist = 0
    for i, val in enumerate(state):
        if val != 0:
            gi = goal.index(val)
            dist += abs(i//3 - gi//3) + abs(i%3 - gi%3)
    return dist

def get_neighbors(state):
    state = list(state)
    z = state.index(0)
    r, c = z//3, z%3
    moves = []
    for dr, dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr, nc = r+dr, c+dc
        if 0 <= nr < 3 and 0 <= nc < 3:
            nz = nr*3+nc
            s = state[:]
            s[z], s[nz] = s[nz], s[z]
            moves.append(tuple(s))
    return moves

def a_star(start):
    heap = [(manhattan(start), 0, start, [])]
    visited = set()
    while heap:
        f, g, state, path = heapq.heappop(heap)
        if state in visited: continue
        visited.add(state)
        path = path + [state]
        if state == goal:
            return path
        for nb in get_neighbors(state):
            if nb not in visited:
                heapq.heappush(heap, (g+1+manhattan(nb), g+1, nb, path))

start = (7, 2, 4, 5, 0, 6, 8, 3, 1)
print("Initial State:")
for i in range(0, 9, 3):
    print(list(start[i:i+3]))

path = a_star(start)
print(f"\nSolution found in {len(path)-1} moves")
print("\nFinal State:")
for i in range(0, 9, 3):
    print(list(path[-1][i:i+3]))
