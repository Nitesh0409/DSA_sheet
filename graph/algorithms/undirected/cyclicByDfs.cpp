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

bool dfsCycle(vector<vector<int>>& adj, vector<bool>& visited, int u, int parent){
        
        visited[u] = true;
        
        for(int& v: adj[u]){
            
            if(!visited[v]){
                if(dfsCycle(adj,visited,v,u)) return true;
            }
            
            else if(v != parent){
                return true;
            }
        }
        return false;
    }

public:

    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // adj formation
        vector<vector<int>> adj = adjFormation(V, edges);

        // check cycle by dfs
        vector<bool>visited(V,false);

        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(dfsCycle(adj, visited, i, -1)) return true;;
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

    cout<<sol.isCycle(V, edges);
    return 0;
}