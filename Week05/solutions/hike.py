# Solving HIKE problem on SPOJ
# Note: This solution will not pass SPOJ's time limit due to the use of Python
# The solution is correct however SPOJ has very slow Python interpreters

import sys

mx_number = int(1e9)

def solution():
    # Read the input until we don't get any more
    while True:
        # Read the input
        line = input()
        # If n is 0, we are done
        if line == '0':
            break
        # Split the line into a list of strings
        n, p1, p2, p3 = map(int, line.split())
        # Create a list of lists to hold the graph
        graph = []
        # Read the graph
        for i in range(n):
            graph.append(list(input().split()))
        # Queue for BFS
        queue = []
        # Add the starting nodes for each player to the queue
        queue.extend([p1-1, p2-1, p3-1]) # players are 1-indexed 
        # Create distance list, nxnxn
        distance = [[[mx_number for i in range(n)] for j in range(n)] for k in range(n)]
        # Set the distance of the starting nodes to 0
        distance[p1-1][p2-1][p3-1] = 0
        # While there are still nodes in the queue
        while queue:
            a = queue.pop(0)
            b = queue.pop(0)
            c = queue.pop(0)
            for i in range(n):
                # If the color of the edge between a and i is the same as the color of the edge
                # between b and c, then we can move a to i. We update the distance and add the
                # new nodes to the queue only if the distance is less than the current distance.
                # We do this for all three players.
                if graph[a][i] == graph[b][c] and distance[a][b][c] + 1 < distance[i][b][c]:
                    distance[i][b][c] = distance[a][b][c] + 1
                    queue.extend([i, b, c])
                if graph[b][i] == graph[a][c] and distance[a][b][c] + 1 < distance[a][i][c]:
                    distance[a][i][c] = distance[a][b][c] + 1
                    queue.extend([a, i, c])
                if graph[c][i] == graph[a][b] and distance[a][b][c] + 1 < distance[a][b][i]:
                    distance[a][b][i] = distance[a][b][c] + 1
                    queue.extend([a, b, i])
        # If the distance from the starting nodes to the same node is less than infinity, then
        # we can get all three players to the same node. Otherwise, we can't.
        res = mx_number
        for i in range(n):
            res = min(res, distance[i][i][i])
        if res == mx_number:
            print('impossible')
        else:
            print(res)


if __name__ == "__main__":
    solution()
