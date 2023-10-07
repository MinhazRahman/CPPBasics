#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main()
{
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Initialize the adjacency matrix with INF values
    vector<vector<int> > graph(n, vector<int>(n, INF));

    // Input edges and their weights
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Assuming an undirected graph
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][k] != INF && graph[k][j] != INF)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    // Find the vertex with the largest closeness centrality
    double maxCloseness = 0.0;
    int maxClosenessVertex = -1;

    for (int i = 0; i < n; ++i)
    {
        double closeness = 0.0;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && graph[i][j] != INF)
            {
                closeness += 1.0 / graph[i][j];
            }
        }

        if (closeness > maxCloseness)
        {
            maxCloseness = closeness;
            maxClosenessVertex = i;
        }
    }

    cout << "All-pairs shortest distances:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (graph[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << "Vertex with the largest closeness centrality: " << maxClosenessVertex << endl;
    cout << "Closeness centrality value: " << maxCloseness << endl;

    return 0;
}
