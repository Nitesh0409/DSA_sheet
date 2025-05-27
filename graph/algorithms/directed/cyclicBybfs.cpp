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
        }

        return adj;
    }

    
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
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