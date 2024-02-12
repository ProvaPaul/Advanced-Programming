#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int from,to,weight;
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

    void bellmanFord(int start) {
        vector<int> distance(V, INT_MAX);
        distance[start] = 0;

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
                cout << "Graph contains a negative weight cycle." << endl;
                return;
            }
        }

        cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of nodes (vertices) and edges: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.addEdge(i, from, to, weight);
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    graph.bellmanFord(start);

    return 0;
}

2-->
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cout << "Enter the number of nodes (vertices) and edges: ";
    cin >> V >> E;

    vector<int> from(E);
    vector<int> to(E);
    vector<int> weight(E);

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < E; i++) {
        cin >> from[i] >> to[i] >> weight[i];
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distance(V, INT_MAX);
    distance[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (distance[from[j]] != INT_MAX && distance[from[j]] + weight[j] < distance[to[j]]) {
                distance[to[j]] = distance[from[j]] + weight[j];
            }
        }
    }

    for (int i = 0; i < E; i++) {
        if (distance[from[i]] != INT_MAX && distance[from[i]] + weight[i] < distance[to[i]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return 0;
        }
    }

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }

    return 0;
}
