#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define UNCOLOURED 0
#define BLACK 500
#define RED 200

using namespace std;

int colourBuildings(vector <vector <int>> &graph, int first_colour) {
    vector <int> colours(graph.size(), UNCOLOURED);
    queue <int> node_queue;

    int total_price = first_colour;

    int source = 1;

    colours[source] = first_colour;
    node_queue.push(source);

    int vertex, connected_vertex;
    while (!node_queue.empty()) {
        vertex = node_queue.front();
        node_queue.pop();

        for (int i = 0; i < graph[vertex].size(); i++) {
            connected_vertex = graph[vertex][i];

            if (connected_vertex >= colours.size()) {
                colours.resize(connected_vertex + 1, UNCOLOURED);
            }

            if (colours[connected_vertex] == UNCOLOURED) {
                if (colours[vertex] == BLACK) {
                    colours[connected_vertex] = RED;
                    total_price += RED;

                } else {
                    colours[connected_vertex] = BLACK;
                    total_price += BLACK;
                }
                node_queue.push(connected_vertex);

            }
        }
    }

    return total_price;
}

int main() {
    int vertices, edges;

    cin >> vertices >> edges;

    vector <vector <int>> graph(vertices + 1);

    int vertex, connected_vertex;
    for (int i = 0; i < edges; i++) {
        cin >> vertex >> connected_vertex;

        graph[vertex].push_back(connected_vertex);

        // For Undirected graphs
        if (vertex != connected_vertex) {
            graph[connected_vertex].push_back(vertex);
        }
    }

    int colouring_price1 = colourBuildings(graph, RED);
    int colouring_price2 = colourBuildings(graph, BLACK);

    if (colouring_price1 < colouring_price2) {
        cout << colouring_price1 << endl;
    } else {
        cout << colouring_price2 << endl;
    }

    return 0;
}
