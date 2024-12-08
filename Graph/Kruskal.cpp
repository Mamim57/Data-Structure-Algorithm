#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// Compare function to sort edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Find function for Union-Find (with path compression)
int find(int parent[], int u)
{
    if (parent[u] == u) return u; // If u is its own parent
    return parent[u] = find(parent, parent[u]); // Path compression
}

// Union function for Union-Find
void unionSets(int parent[], int rank[], int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rank[rootU] < rank[rootV])
    {
        parent[rootU] = rootV;
    }
    else if (rank[rootU] > rank[rootV])
    {
        parent[rootV] = rootU;
    }
    else
    {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Kruskal's Algorithm
void kruskal(int V, vector<Edge>& edges)
{
    sort(edges.begin(), edges.end(), compare); // Sort edges by weight

    int parent[V], rank[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i; // Each vertex is its own parent initially
        rank[i] = 0;   // Rank is 0 for all vertices
    }

    int mstWeight = 0; // Total weight of MST
    vector<Edge> mstEdges; // Edges included in the MST

    for (Edge& edge : edges)
    {
        // If including this edge doesn't cause a cycle
        if (find(parent, edge.u) != find(parent, edge.v))
        {
            mstEdges.push_back(edge); // Add edge to MST
            mstWeight += edge.weight; // Add weight to MST
            unionSets(parent, rank, edge.u, edge.v); // Union the sets
        }
    }

    // Output the MST
    cout << "Edges in MST:\n";
    for (Edge& edge : mstEdges)
    {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
    cout << "Total weight of MST: " << mstWeight << endl;
}

int main()
{
    int V = 4; // Number of vertices
    vector<Edge> edges =   // Graph edges
    {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(V, edges); // Run Kruskal's Algorithm
    return 0;
}

