#include<bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> adjFormation(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    bool bfs(vector<vector<int>> &adj, vector<int> &color, int u, int c)
    {
        color[u] = c;
        queue<int> q;
        q.push(u);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int &v : adj[curr])
            {
                if (color[v] == -1)
                {
                    q.push(v);
                    color[v] = 1 - color[curr];
                }
                else if (color[v] == color[curr])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj = adjFormation(V, edges);
        vector<int> color(V, -1);

        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(adj, color, i, 0))
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;

    // Example 1: Bipartite graph
    int V1 = 4;
    vector<vector<int>> edges1 = {
        {0, 1}, {0, 3}, {1, 2}, {2, 3}};

    // Example 2: Non-bipartite graph
    int V2 = 3;
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {2, 0}};

    cout << "Graph 1 is " << (sol.isBipartite(V1, edges1) ? "Bipartite" : "Not Bipartite") << endl;
    cout << "Graph 2 is " << (sol.isBipartite(V2, edges2) ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}
