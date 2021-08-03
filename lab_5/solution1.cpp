#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> breadthFirstSearch(vector <vector <int>> &graph, int source) {
    queue <int> qu;
    vector <int> distances(graph.size(), -1);

    distances[source] = 0;
    qu.push(source);

    int vertex, connected_vertex;

    while (!qu.empty()) {
        vertex = qu.front();
        qu.pop();

        for (int i = 0; i < graph[vertex].size(); i++) {
            connected_vertex = graph[vertex][i];

            if (connected_vertex >= distances.size()) {
                distances.resize(connected_vertex + 1, -1);
            }

            if (distances[connected_vertex] == -1) {
                distances[connected_vertex] = 1 + distances[vertex];
                qu.push(connected_vertex);
            }
        }
    }

    return distances;
}

int main() {
    int vertices, edges;

    cin >> vertices >> edges;

    vector <vector <int>> graph(vertices + 1);

    int vertex, connected_vertex;
    for (int i = 0; i < edges; i++) {
        cin >> vertex >> connected_vertex;

        graph[vertex].push_back(connected_vertex);

        // For Undiredted graphs
        if (vertex != connected_vertex) {
            graph[connected_vertex].push_back(vertex);
        }
    }

    vector <int> distances = breadthFirstSearch(graph, 1);

    int farthest_vertex = *max_element(distances.begin(), distances.end());

    cout << farthest_vertex << endl;

    return 0;
}
