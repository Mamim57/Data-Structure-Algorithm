#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Represents infinity

void prim(int V, int G[5][5])
{
    int parent[V];   // Stores MST
    int key[V];      // Minimum weights to add vertices
    bool mstSet[V];  // Tracks vertices in MST

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;   // Initialize all keys to infinity
        mstSet[i] = false; // Mark all vertices as not in MST
    }

    key[0] = 0;       // Start from the first vertex
    parent[0] = -1;   // The root node has no parent

    for (int count = 0; count < V - 1; count++)
    {
        // Find the minimum key vertex not yet in MST
        int u = -1;
        for (int i = 0; i < V; i++)
        {
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
            {
                u = i;
            }
        }

        mstSet[u] = true; // Include this vertex in MST

        // Update adjacent vertices of u
        for (int v = 0; v < V; v++)
        {
            if (G[u][v] && !mstSet[v] && G[u][v] < key[v])
            {
                key[v] = G[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " - " << i << " \t" << G[i][parent[i]] << endl;
    }
}

int main()
{
    int V = 5; // Number of vertices
    int G[5][5] =   // Adjacency matrix representation
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(V, G); // Run Prim's Algorithm
    return 0;
}

