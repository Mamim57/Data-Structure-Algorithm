#include <bits/stdc++.h>
using namespace std;

int V = 5; // Number of vertices in the graph
int G[5][5] =   // Adjacency matrix representation of the graph
{
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 0},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 0, 1, 1, 0}
};

void graphColoring()
{
    int result[5]; // Array to store color assignments for vertices
    bool available[5]; // Array to track available colors

    // Initialize all vertices as uncolored
    for (int i = 0; i < V; i++)
    {
        result[i] = -1;
    }

    // Assign the first color to the first vertex
    result[0] = 0;

    // Assign colors to remaining vertices
    for (int u = 1; u < V; u++)
    {
        // Initialize all colors as available
        for (int i = 0; i < V; i++)
        {
            available[i] = true;
        }

        // Mark colors of adjacent vertices as unavailable
        for (int i = 0; i < V; i++)
        {
            if (G[u][i] == 1 && result[i] != -1)
            {
                available[result[i]] = false;
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < V; color++)
        {
            if (available[color]) break;
        }

        // Assign the found color to the current vertex
        result[u] = color;
    }

    // Print the result
    cout << "Vertex -> Color\n";
    for (int u = 0; u < V; u++)
    {
        cout << u << " -> " << result[u] << endl;
    }
}

int main()
{
    graphColoring();
    return 0;
}

