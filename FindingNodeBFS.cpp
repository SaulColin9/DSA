#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Graph {
    int V;
    std::vector<std::list<int>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    std::vector<int> nodesAtDistanceK(int start, int k);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

std::vector<int> Graph::nodesAtDistanceK(int start, int k) {
    std::vector<bool> visited(V, false);
    std::vector<int> distance(V, 0);
    std::queue<int> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                queue.push(neighbor);
            }
        }
    }

    std::vector<int> result;
    for (int i = 0; i < V; ++i) {
        if (distance[i] == k) {
            result.push_back(i);
        }
    }

    return result;
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
    int k = 2;
    std::vector<int> result = g.nodesAtDistanceK(start, k);

    return 0;
}
