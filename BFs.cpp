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
    std::vector<int> BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

std::vector<int> Graph::BFS(int s) {
    std::vector<bool> visited(V, false);
    std::queue<int> queue;
    std::vector<int> bfs_order;

    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        bfs_order.push_back(s);
        queue.pop();

        for (auto adjVertex : adj[s]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    return bfs_order;
}

int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::vector<int> bfs_result = g.BFS(2);
    for (int v : bfs_result) {
        std::cout << v << " ";
    }

    return 0;
}
