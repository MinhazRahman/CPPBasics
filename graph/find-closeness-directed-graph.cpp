#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

const int INF = INT_MAX;

// this method prints the adjacency matrix
template <typename T>
void printAdjacencyMatrix(T matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, m; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of directed edges: ";
    cin >> m;

    // Initialize the adjacency matrix with INF values
    vector<vector<int> > graph(n, vector<int>(n, INF));

    // Set diagonal values to zero
    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
    }

    // Input directed edges and their weights
    for (int i = 0; i < m; i++)
    {
        int s, d, w;
        cout << "Enter directed edge " << i + 1 << " (source, destination, weight): ";
        cin >> s >> d >> w;
        graph[s][d] = w;
    }

    cout << "\nPrint the initial adjacency matrix: " << endl;
    printAdjacencyMatrix(graph, n);

    // Apply Floyd-Warshall algorithm and find the all terminal shortest distances
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
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

    for (int i = 0; i < n; i++)
    {
        double closeness = 0.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] != INF)
            {
                closeness += 1.0 / graph[i][j];
            }
        }
        closeness /= (n - 1); // Normalize by the number of other vertices

        if (closeness > maxCloseness)
        {
            maxCloseness = closeness;
            maxClosenessVertex = i;
        }
    }

    cout << "\nAll-pairs shortest distances for directed graph:" << endl;
    printAdjacencyMatrix(graph, n);

    cout << "\nVertex with the largest closeness centrality: " << maxClosenessVertex << endl;
    cout << "\n" << endl;
    
    return 0;
}
