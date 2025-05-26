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

    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int u, stack<int> &st)
    {
        visited[u] = true;

        for (int &v : adj[u])
        {
            if (!visited[v])
            {
                dfs(adj, visited, v, st);
            }
        }

        st.push(u);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        // graph foramtion:
        vector<vector<int>> adj = adjFormation(V, edges);

        // topological sort
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(adj, visited, i, st);
            }
        }

        // solution return
        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        return result;
    }
};


int main(){

    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}, {2, 5}, {3, 4}, {4, 5}};
    int V = 6;

    vector<int> result = sol.topoSort(V, edges);

    for(int & val : result){
        cout << val << ' ';
    }
    return 0;
}