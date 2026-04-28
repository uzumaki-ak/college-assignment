from itertools import permutations

dist = {
    ('X','Y'):10, ('X','Z'):15, ('X','W'):20,
    ('Y','X'):10, ('Y','Z'):35, ('Y','W'):25,
    ('Z','X'):15, ('Z','Y'):35, ('Z','W'):30,
    ('W','X'):20, ('W','Y'):25, ('W','Z'):30
}

cities = ['X', 'Y', 'Z', 'W']

def tsp(cities, dist):
    best, best_path = float('inf'), None
    for perm in permutations(cities[1:]):
        path = [cities[0]] + list(perm) + [cities[0]]
        cost = sum(dist[(path[i], path[i+1])] for i in range(len(path)-1))
        if cost < best:
            best, best_path = cost, path
    return best, best_path

cost, path = tsp(cities, dist)
print("Optimal Path:", ' -> '.join(path))
print("Minimum Cost:", cost)
