def main():
    n, m = map(int, input().split())
    graph = []
    for i in range(n):
        graph.append(input())
    visited = set()
    count = 0
    for i in range(n):
        for j in range(m):
            if (i, j) not in visited:
                just_visited = set()
                node = (i, j)
                while node not in just_visited:
                    if node in visited:
                        break
                    just_visited.add(node)
                    visited.add(node)
                    if graph[node[0]][node[1]] == 'N' and node[0] > 0:
                        node = (node[0]-1, node[1])
                    elif graph[node[0]][node[1]] == 'S' and node[0] < n-1:
                        node = (node[0]+1, node[1])
                    elif graph[node[0]][node[1]] == 'E' and node[1] < m-1:
                        node = (node[0], node[1]+1)
                    elif graph[node[0]][node[1]] == 'W' and node[1] > 0:
                        node = (node[0], node[1]-1)
                    else:
                        break
                if node in just_visited:
                    count += 1
    print(count)

if __name__ == "__main__":
    main()