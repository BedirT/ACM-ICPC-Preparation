// Same as the python solution, but in C++.

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> graph;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        graph.push_back(s);
    }
    set<pair<int, int>> visited;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited.find({i, j}) == visited.end()) {
                set<pair<int, int>> just_visited;
                pair<int, int> node = {i, j};
                while (just_visited.find(node) == just_visited.end()) {
                    if (visited.find(node) != visited.end()) {
                        break;
                    }
                    just_visited.insert(node);
                    visited.insert(node);
                    if (graph[node.first][node.second] == 'N' && node.first > 0) {
                        node = {node.first-1, node.second};
                    } else if (graph[node.first][node.second] == 'S' && node.first < n-1) {
                        node = {node.first+1, node.second};
                    } else if (graph[node.first][node.second] == 'E' && node.second < m-1) {
                        node = {node.first, node.second+1};
                    } else if (graph[node.first][node.second] == 'W' && node.second > 0) {
                        node = {node.first, node.second-1};
                    } else {
                        break;
                    }
                }
                if (just_visited.find(node) != just_visited.end()) {
                    count += 1;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}