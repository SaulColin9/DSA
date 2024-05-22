#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>

class Graph {
    int V;
    std::vector<std::list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    std::vector<int> BFS(int start, int end);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

std::vector<int> Graph::BFS(int start, int end) {
    std::vector<bool> visited(V, false);
    std::vector<int> predecessor(V, -1);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                predecessor[neighbor] = current;
                queue.push(neighbor);

                if (neighbor == end) {
                    std::vector<int> path;
                    for (int at = end; at != -1; at = predecessor[at]) {
                        path.push_back(at);
                    }
                    std::reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }
    return {};
}

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    int start = 0;
    int end = 5;
    std::vector<int> path = g.BFS(start, end);

    return 0;
}
