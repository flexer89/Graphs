#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>

using std::cout;
using std::endl;

struct weightedEdge
{
    int s;
    int t;
    double w; 
};

class WeightedGraph
{
private:
    int** adjWeightMatrix;
    int n;                      
    bool directed;
public:
    WeightedGraph(int N, int m, weightedEdge edges[], bool Directed);
    void Dijkstra(int s);
    int find(int* d, int* S, int n);
    void printSolutions(int s, int* d, int* parent);
    void WarshallFloyd();
};