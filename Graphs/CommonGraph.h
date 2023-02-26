#pragma once
#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

struct edge
{
    int s;     
    int t;     
};


class Graph
{
private:
    int** adjMatrix;
    int n;                                            
    bool directed;                                     
    void dfs(int s, bool* visited);                    
public:
    Graph(int N, int m, edge edges[], bool Directed);   
    void bfs(int s);                                    
    void dfs(int s);                                    
    int connected();
    friend ostream& operator<<(ostream& out, Graph& g); 
    ~Graph();                                          
};