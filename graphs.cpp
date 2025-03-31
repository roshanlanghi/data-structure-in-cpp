#include <iostream>
using namespace std;

class Graph {
private:
    int vertices;
    int adjMatrix[100][100]; // Using a fixed-size array

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0; // Initialize matrix with 0
            }
        }
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // For an undirected graph
    }

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