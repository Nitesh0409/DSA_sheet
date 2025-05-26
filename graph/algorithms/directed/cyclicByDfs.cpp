#include<bits/stdc++.h>

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
        }

        return adj;
    }

    bool dfsCycle(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack, int u)
    {

        visited[u] = true;
        recStack[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                if (dfsCycle(adj, visited, recStack, v))
                    return true;
            }
            else if (recStack[v])
            {
                return true;
            }
        }

        recStack[u] = false;

        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here

        // graph formation
        vector<vector<int>> adj = adjFormation(V, edges);

        // cycle detection by dfs
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfsCycle(adj, visited, recStack, i))
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

    cout << sol.isCyclic(V, edges);
    return 0;
}