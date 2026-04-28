graph = {
    'P': ['Q', 'R'],
    'Q': ['S', 'T'],
    'R': ['T'],
    'S': [],
    'T': ['U'],
    'U': []
}

def dfs(graph, node, visited=None):
    if visited is None:
        visited = []
    if node not in visited:
        visited.append(node)
        for neighbor in graph[node]:
            dfs(graph, neighbor, visited)
    return visited

print("DFS Traversal:", dfs(graph, 'P'))
