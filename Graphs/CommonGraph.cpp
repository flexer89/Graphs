#include "CommonGraph.h"

Graph::Graph(int N, int m, edge edges[], bool Directed)
{
    adjMatrix = new int* [N];
    for (int i = 0; i < N; i++)
        adjMatrix[i] = new int[N] {};

    n = N;
    directed = Directed;

    for (int i = 0; i < m; i++)
    {
        adjMatrix[edges[i].s][edges[i].t] = 1;
        if (!directed)
            adjMatrix[edges[i].t][edges[i].s] = 1;
    }



}

void Graph::bfs(int s)
{
    bool* visited = new bool[n] {};
    visited[s] = 1;

    queue<int> q;
    q.push(s);

    cout << "BFS: ";

    while (!q.empty())
    {
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[q.front()][i] == 1 && visited[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        cout << q.front() << ' ';
        q.pop();
    }

    cout << endl;

    delete[] visited;
}

void Graph::dfs(int s, bool* visited)
{
    visited[s] = 1;
    cout << s << ' ';

    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[s][i] == 1 && visited[i] == 0)
            dfs(i, visited);
    }
}

void Graph::dfs(int s)
{
    bool* visited = new bool[n] {};
    visited[s] = 1;
    cout << "DFS: ";
    dfs(s, visited);
    cout << endl;
    delete[] visited;
}

int Graph::connected()
{
    bool* visited = new bool[n] {false};
    int parts = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, visited);
            parts++;
        }
    }
    return parts;
}

Graph::~Graph()
{
    for (int i = 0; i < n; i++)
        delete adjMatrix[i];
    delete adjMatrix;
}

ostream& operator<<(ostream& out, Graph& g)
{
    for (int i = 0; i < g.n; i++)
    {
        out << i + 1 << ". ";
        for (int j = 0; j < g.n; j++)
        {
            out << g.adjMatrix[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}


