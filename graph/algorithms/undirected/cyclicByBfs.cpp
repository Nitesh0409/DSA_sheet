#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> adjFormation(int v, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(v);

        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // for undirected graph
        }

        return adj;
    }

    bool bfsCycle(vector<vector<int>> &adj, vector<bool> &visited, int start, int parent)
    {
        queue<pair<int, int>> q;
        q.push({start, parent});
        visited[start] = true;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            int u = p.first;
            int par = p.second;

            for (int &v : adj[u])
            {
                if (!visited[v])
                {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if (v != par)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // adj formation
        vector<vector<int>> adj = adjFormation(V, edges);

        // check cycle by bfs
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (bfsCycle(adj, visited, i, -1))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}, {2, 5}};
    int V = 6;

    cout << sol.isCycle(V, edges);
    return 0;
}