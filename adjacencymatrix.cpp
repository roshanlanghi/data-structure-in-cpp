#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int adjMatrix[100][100]; // Fixed-size adjacency matrix

public:
    // Constructor
    Graph(int v) {
        vertices = v;

        // Initialize adjacency matrix with 0
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Function to add an edge
    void addEdge(int src, int dest) {
        if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
            adjMatrix[src][dest] = 1;  // Mark the edge
            adjMatrix[dest][src] = 1;  // Since it's an undirected graph
        } else {
            cout << "Invalid edge!" << endl;
        }
    }

    // Function to display adjacency matrix
    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter edges (source destination):" << endl;
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    g.display();
    return 0;
}
