import heapq

def dijkstra_shortest_path(graph, start_node, end_node):
    # Priority Queue stores (time, current_node)
    queue = [(0, start_node)]
    times = {node: float('infinity') for node in graph}
    times[start_node] = 0
    previous_nodes = {node: None for node in graph}

    while queue:
        current_time, current_node = heapq.heappop(queue)

        # Stop if we reached the destination
        if current_node == end_node:
            break

        if current_time > times[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            new_time = current_time + weight
            if new_time < times[neighbor]:
                times[neighbor] = new_time
                previous_nodes[neighbor] = current_node
                heapq.heappush(queue, (new_time, neighbor))

    # Reconstruct path
    path = []
    curr = end_node
    while curr:
        path.insert(0, curr)
        curr = previous_nodes[curr]
    
    return path, times[end_node]

# Define the City Map (Graph)
# Nodes are Intersections, Numbers are Minutes to travel
city_map = {
    'Station': {'Point A': 5, 'Point B': 2},
    'Point A': {'Station': 5, 'Hospital': 4, 'Point C': 2},
    'Point B': {'Station': 2, 'Point C': 1, 'Hospital': 7},
    'Point C': {'Point A': 2, 'Point B': 1, 'Hospital': 3},
    'Hospital': {'Point A': 4, 'Point C': 3, 'Point B': 7}
}

path, total_time = dijkstra_shortest_path(city_map, 'Station', 'Hospital')

print(f"Fastest Route: {path}")
print(f"Total Time: {total_time} minutes")
