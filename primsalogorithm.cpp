#include <iostream>
using namespace std;

#define INF 999
#define MAX 100

void primsGraph(int cost[MAX][MAX], int vertices) {
    int minCost = 0;
    int edgeCount = 1;
    bool visited[MAX] = {false};
    visited[0] = true;

    while (edgeCount < vertices) { 
        int min = INF;
        int x = 0, y = 0;

        for (int i = 0; i < vertices; i++) {
            if (visited[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!visited[j] && cost[i][j] <= min) { 
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = true; 
        cout << "Edge is (" << x << ", " << y << ") with cost " << cost[x][y] << endl;
        minCost += cost[x][y]; 
        edgeCount++;
    }
    cout << "Minimum Cost of the spanning tree: " << minCost << endl;
}

int main() {
    int vertices, edges;
    int cost[MAX][MAX];

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    // Initialize cost matrix with INF
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cost[i][j] = (i == j) ? 0 : INF;
        }
    }

    cout << "Enter the number of edges: ";
    cin >> edges;
    
    cout << "Enter edges in the format (u v weight):\n";
    for (int i = 0; i < edges; i++) { 
        int u, v, weight;
        cin >> u >> v >> weight;
        cost[u-1][v-1] = weight;
         cost[v-1][u-1] = weight;  
    }

    primsGraph(cost, vertices);

    return 0;
}