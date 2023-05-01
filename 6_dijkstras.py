from heapq import heapify,heappop,heappush
import math

def dijsktra(graph,source,destination):
    node_data = {
        "A":{
            "cost":math.inf,
            "pred":[]
        },
        "B":{
            "cost":math.inf,
            "pred":[]
        },
        "C":{
            "cost":math.inf,
            "pred":[]
        },
        "D":{
            "cost":math.inf,
            "pred":[]
        },
        "E":{
            "cost":math.inf,
            "pred":[]
        },
    }

    node_data[source]["cost"] = 0
    visited = []

    current_src = source
    for i in range(len(graph) - 1):
        if current_src not in visited:
            visited.append(current_src)
            min_heap = []
            for j in graph[current_src]:
                if j not in visited:
                    cost = node_data[current_src]["cost"] + graph[current_src][j]

                    if cost < node_data[j]["cost"]:
                        node_data[j]["cost"] = cost
                        
                        node_data[j]["pred"] = node_data[current_src]["pred"] +  [current_src]   
                    
                    heappush(min_heap,(node_data[j]["cost"],j))
        
        current_src = heappop(min_heap)[1]
    
    print(node_data[destination]["pred"] + list(destination))
                        

graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1, 'E': 3},
    'D': {'B': 5, 'C': 1, 'E': 6},
    'E': {'C': 3, 'D': 6}
}
source = "A"
destination = "E"

dijsktra(graph,source,destination)