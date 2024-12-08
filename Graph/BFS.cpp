#include <bits/stdc++.h>
using namespace std;

int V = 5; // Number of nodes in the graph
int visited[5];
int G[5][5] =
{
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

// Breadth-First Search (BFS) function
void BFS(int v)
{
    queue<int> Q;
    for (int i = 0; i < V; i++) visited[i] = 0; // Reset visited status

    visited[v] = 1;
    cout << "BFS node from " << v << " : ";
    cout << v << " ";
    Q.push(v);

    while (!Q.empty())
    {
        int current = Q.front();
        Q.pop();

        for (int j = 0; j < V; j++)
        {
            if (G[current][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                cout << j << " ";
                Q.push(j);
            }
        }
    }
    cout << endl;
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        BFS(i); // Perform BFS starting from node `i`
    }
}

