# Depth First Search (DFS) implementation
#
# A simple implementation of DFS using a queue
# with in depth comments
#
# Author: BedirT

def dfs(graph, start, goal):
    # Initialize a stack with the start node
    stack = [start]
    # Initialize a set to keep track of visited nodes
    visited = set()
    # Create a list to keep track of the order in which we visit the nodes
    # This is not necessary for the algorithm to work visited set is enough
    # But it is useful for visualization
    order = []
    # While the stack is not empty
    while stack:
        # Pop the last element from the stack
        node = stack.pop()
        # If the node has not been visited
        if node not in visited:
            # Mark the node as visited
            visited.add(node)
            # Add the node to the order list
            order.append(node)
            # If the node is the goal, return the path
            if node == goal:
                return order
            # Add the neighbors of the node to the stack
            stack.extend(graph[node])
    # If the stack is empty, return None
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
    print(dfs(graph, 'A', 'F'))

    # Output: ['A', 'C', 'F']

    # Another example
    graph = {
        'A': ['B', 'C'],
        'B': ['A'],
        'C': ['A'],
        'G': ['H'],
        'H': ['G']
    }
    print(dfs(graph, 'A', 'H'))

    # Output: None