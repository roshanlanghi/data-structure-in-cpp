import java.util.Scanner;
import java.util.Arrays;

public class PrimsAlgorithm {
 static void primsGraph(int[][] cost, int vertices) {
        int minCost = 0;        
        int edgeCount = 1;      
        boolean[] visited = new boolean[vertices];
        Arrays.fill(visited, false); 
        visited[0] = true;      

        while (edgeCount < vertices) {
            int INF = 999;     
            int min = INF;
            int x = 0, y = 0;   

            
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
            System.out.printf("Edge is (%d, %d) with cost %d\n", x, y, cost[x][y]);
            minCost += cost[x][y];
            edgeCount++;
        }
        System.out.println("Minimum Cost of the spanning tree: " + minCost);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices in the graph: ");
        int vertices = sc.nextInt();
        int[][] cost = new int[vertices][vertices];
        System.out.println("Enter the adjacency matrix (use 999 for no connection):");
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                System.out.printf("Enter the weight at (%d, %d): ", i, j);
                cost[i][j] = sc.nextInt();
            }
        }
        primsGraph(cost, vertices);
    }
}