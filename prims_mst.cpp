#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from, to, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;

    Graph(int vertices, int edgesCount) {
        V = vertices;
        E = edgesCount;
        edges.resize(E);
    }

    void addEdge(int index, int from, int to, int weight) {
        edges[index] = {from, to, weight};
    }

    bool hasNegativeCycle() {
        vector<int> distance(V, INT_MAX);
        distance[0] = 0;

        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int from = edges[j].from;
                int to = edges[j].to;
                int weight = edges[j].weight;

                if (distance[from] != INT_MAX && distance[from] + weight < distance[to]) {
                    distance[to] = distance[from] + weight;
                }
            }
        }

        for (int i = 0; i < E; i++) {
            int from = edges[i].from;
            int to = edges[i].to;
            int weight = edges[i].weight;

            if (distance[from] != INT_MAX && distance[from] + weight < distance[to]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cout << "number of nodes and edges: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.addEdge(i, from, to, weight);
    }

    if (graph.hasNegativeCycle()) {
        cout << "Negative cycle detected in the graph." << endl;
    } else {
        cout << "No negative cycle in the graph." << endl;
    }

}

