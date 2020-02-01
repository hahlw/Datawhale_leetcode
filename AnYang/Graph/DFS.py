# 20200201 Sat
# 6个节点图的BFS

graph = {
    "A": ["B", "C"],
    "B": ["A", "C", "D"],
    "C": ["A", "B", "D", "E"],
    "D": ["B", "C", "E", "F"],
    "E": ["C", "D"],
    "F": ["D"]
}

def DFS(graph, s):
    stack = []
    stack.append(s)
    seen = set()
    seen.add(s)
    ans = []
    while(len(stack) > 0):
        vertex = stack.pop(-1)
        nodes = graph[vertex]
        for w in nodes:
            if w not in seen:
                stack.append(w)
                seen.add(w)
        ans.append(vertex)
    print(ans)


DFS(graph, "A")