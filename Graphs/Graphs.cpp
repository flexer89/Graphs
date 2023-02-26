#include <iostream>
#include "CommonGraph.h"
#include "WeightedGraph.h"

int main()
{
    int n = 6;
    int m = 15;
    edge directedGraph[] = { {0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4} };  
    weightedEdge edges[] = { {0, 1, 3}, {0, 3, 1}, {0, 4, 6},
                       {1, 2, 2}, {2, 5, 8}, {3, 1, 1},
                       {3, 2, 6}, {3, 4, 2}, {3, 5, 7},
                        {4, 0, 6}, {4, 3, 2}, {4, 5, 4} };
    Graph g1(n, m, directedGraph, true);
    cout << g1 << endl;
    g1.bfs(0);
    g1.dfs(0);
    cout << endl << "Check if graph is connected: " << g1.connected();
    cout << endl;
    cout << endl;
    cout << endl;

    n = 6; 
    m = 12;

    WeightedGraph g2(n, m, edges, true);
    g2.Dijkstra(0);
    g2.WarshallFloyd();
    cout << endl;
    cout << endl;
    cout << endl;

    n = 6, m = 15;
    weightedEdge test[] = { {0,4,6},{0,5,1},{1,0,2},{1,2,5},{1,4,1},{2,1,3},{2,3,2},{2,4,1},{3,2,1},{3,5,4},{4,0,6},{4,1,4},{4,3,2},{5,3,1},{5,4,1} };
    WeightedGraph g3(n, m, test, true);
    g3.Dijkstra(0);
    g3.WarshallFloyd();
}