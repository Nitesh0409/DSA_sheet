// this algorith is same for undirected and directed graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

    void bfs(vector<vector<int>> &adj, vector<bool> &visited, int u, vector<int> &result)
    {
        queue<int> q;
        q.push(u);

        visited[u] = true;

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            result.push_back(temp);

            for (int &v : adj[temp])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
};

int main()
{
    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}, {2, 5}};
    int V = 6;

    // by adj list
    vector<vector<int>> adj = sol.adjFormation(V, edges);

    vector<bool> visited(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            sol.bfs(adj, visited, i, result);
        }
    }

    for (int &node : result)
    {
        cout << node << " ";
    }

    return 0;
}