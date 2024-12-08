#include <bits/stdc++.h>
using namespace std;

int V = 5; // Number of nodes in the graph
int visited[5]; // To track visited status of each node
int G[5][5] =   // Adjacency matrix representation of the graph
{
    {0, 1, 0, 0, 1},
    {1, 0, 0, 1, 1},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {1, 1, 0, 1, 0}
};

// Depth-First Search (DFS) function
void DFS(int v)
{
    visited[v] = 1; // Mark the current node as visited
    cout << v << " "; // Print the visited node

    for (int i = 0; i < V; i++)
    {
        // If there is a connection and the node is not visited
        if (G[v][i] == 1 && visited[i] == 0)
        {
            DFS(i); // Recursive call for the connected node
        }
    }
}

int main()
{
    for (int i = 0; i < V; i++)
    {
        // Reset visited array for each DFS traversal
        for (int j = 0; j < V; j++) visited[j] = 0;

        // Perform DFS starting from node `i`
        cout << "DFS starting from node " << i << " : ";
        DFS(i);
        cout << endl;
    }
}

