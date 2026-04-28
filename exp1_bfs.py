from collections import deque

graph = {
    'S': ['A', 'B'],
    'A': ['C', 'D'],
    'B': ['D', 'E'],
    'C': [],
    'D': ['F'],
    'E': ['F'],
    'F': []
}

def bfs(graph, start):
    visited = []
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            queue.extend(graph[node])
    return visited

print("BFS Traversal:", bfs(graph, 'S'))
