# Breadth First Search (BFS) implementation
#
# A simple implementation of BFS using a queue
# with in depth comments
#
# Author: BedirT

def bfs(graph, start, goal):
    # Initialize a queue with the start node
    queue = [start]
    # Initialize a set to keep track of visited nodes
    visited = set()
    # Create a list to keep track of the order in which we visit the nodes
    # This is not necessary for the algorithm to work visited set is enough
    # But it is useful for visualization
    order = []
    # While the queue is not empty
    while queue:
        # Pop the first element from the queue
        node = queue.pop(0)
        # If the node has not been visited
        if node not in visited:
            # Mark the node as visited
            visited.add(node)
            # Add the node to the order list
            order.append(node)
            # If the node is the goal, return the path
            if node == goal:
                return order
            # Add the neighbors of the node to the queue
            queue.extend(graph[node])
    # If the queue is empty, return None
    return None


if __name__ == "__main__":
    # Example usage
    graph = {
        'A': ['B', 'C'],
        'B': ['A', 'D', 'E'],
        'C': ['A', 'F'],
        'D': ['B'],
        'E': ['B', 'F'],
        'F': ['C', 'E']
    }
    print(bfs(graph, 'A', 'F'))

    # Output: ['A', 'B', 'C', 'D', 'E', 'F']

    # Another example
    graph = {
        'A': ['B', 'C'],
        'B': ['A'],
        'C': ['A'],
        'G': ['H'],
        'H': ['G']
    }
    print(bfs(graph, 'A', 'H'))

    # Output: None

