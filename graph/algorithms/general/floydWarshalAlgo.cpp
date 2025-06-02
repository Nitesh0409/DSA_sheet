#include <bits/stdc++.h>

using namespace std;

/*
    Floyd-Warshall Algorithm:
    Finds shortest paths between all pairs of nodes in a graph.

    Handles negative weights but not negative cycles.
*/

class Solution
{
public:
    vector<vector<int>> floydWarshall(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));  //distance matrix

        // Set self distances to 0
        for (int i = 0; i < V; ++i)
            dist[i][i] = 0;

        for (auto &edge : edges)  //updating distance of every edge  
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int via = 0; via < V; via++)  // via every vertex
        {
            for (int i = 0; i < V; ++i)
            {
                for (int j = 0; j < V; ++j)
                {
                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        return dist;
    }
};

int main()
{
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 3, 10},
        {1, 2, 3},
        {2, 3, 1}};

    Solution sol;
    vector<vector<int>> result = sol.floydWarshall(V, edges);

    cout << "All-pairs shortest path matrix:\n";
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if (result[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
