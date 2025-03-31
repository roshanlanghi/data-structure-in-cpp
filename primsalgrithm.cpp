#include<iostream>
using namespace std;
void primsGraph(int cost[MAX][MAX], int vertices) {
    int minCost = 0;
    int edgeCount = 1;
    bool visited[MAX] = {false}; // Track visited nodes
    visited[0] = true; // Start with the first vertex

    while (edgeCount < vertices) {
        int min = INF;
        int x = 0, y = 0;

        // Find the minimum weight edge
        for (int i = 0; i < vertices; i++) {  
            if (visited[i]) {
                for (int j = 0; j < vertices; j++) {
                    if (!visited[j] && cost[i][j] < min) {
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
int main()
{
    int vertices;
    int cost[100][100];

   cout<<"accept the no of vertices:"<<endl;
   cin>>vertices;
   cout<<"enter the adjecency matrix"<<endl;
   cin>>cost ;


}