#include "WeightedGraph.h"

WeightedGraph::WeightedGraph(int N, int m, weightedEdge edges[], bool Directed)
{
    n = N;
    directed = Directed;

    adjWeightMatrix = new int* [n];

    for (int i = 0; i < n; i++)
    {
        adjWeightMatrix[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            adjWeightMatrix[i][j] = INT_MAX;
            if (i == j)
                adjWeightMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        adjWeightMatrix[edges[i].s][edges[i].t] = edges[i].w;
        if (directed == false)
            adjWeightMatrix[edges[i].t][edges[i].s] = edges[i].w;
    }

}

void WeightedGraph::Dijkstra(int s)
{
    int* d = new int[n];
    int* parent = new int[n];
    int* S = new int[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = INT_MAX;
        S[i] = 0;
        parent[i] = -1;
    }

    d[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = find(d, S, n);
        S[u] = 1;

        for (int j = 0; j < n; j++)
        {
            if (adjWeightMatrix[u][j] != INT_MAX && adjWeightMatrix[u][j] != 0 && u != j)
            {
                if (d[j] > d[u] + adjWeightMatrix[u][j])
                {
                    d[j] = d[u] + adjWeightMatrix[u][j];
                    parent[j] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << std::setw(2) << S[i] << ", ";

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << std::setw(2) << parent[i] << ", ";

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << std::setw(2) << d[i] << ", ";

    int t = 4;
    cout << endl;
    printSolutions(s, d, parent);
}

int WeightedGraph::find(int* d, int* S, int n)
{
    int min = 1000;
    int indeks = -1;

    for (int i = 0; i < n; i++)
    {
        if (S[i] == 0)
        {
            if (d[i] < min)
            {
                min = d[i];
                indeks = i;
            }
        }
    }

    return indeks;
}

void WeightedGraph::printSolutions(int s, int* d, int* parent)
{
    std::stack<int> st;
    int distance = 0;
    int temp = 0;

    for (int i = 0; i < n; i++)
    {
        std::cout << "The shortest path to " << i << ": ";
        distance = d[i];
        temp = i;

        while (distance != 0)
        {
            st.push(temp);
            temp = parent[temp];
            distance = d[temp];
        }

        std::cout << "0 ";

        while (!st.empty())
        {
            std::cout << st.top() << " ";
            st.pop();
        }
        std::cout << std::endl;
    }

}
void WeightedGraph::WarshallFloyd()
{
    double** distance = new double* [n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            distance[i][j] = adjWeightMatrix[i][j];
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][j] > distance[i][k] + distance[k][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Paths from vertex " << i << " to other vertices. ";
        for (int j = 0; j < n; j++)
        {
            if (distance[i][j] == INT_MAX)
                cout << std::setw(3) << "INF" << " ";
            else
                cout << std::setw(3) << distance[i][j] << " ";
        }
        cout << endl;
    }


}
