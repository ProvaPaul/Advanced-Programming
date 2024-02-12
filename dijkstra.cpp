#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int V, E;
    cout << "Enter the number of nodes (vertices) and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>> > adj(V); // Use a vector of pairs for the adjacency list: (to, weight)

    cout << "Enter the edges and their weights:" << endl;
    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back(make_pair(to, weight));
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distance(V, INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }

    return 0;
}
