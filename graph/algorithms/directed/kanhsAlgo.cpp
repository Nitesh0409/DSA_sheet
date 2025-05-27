//this is topological sort by bfs

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

    void indeg(int v, vector<vector<int>>& adj, vector<int>& indegree){
        for (int u = 0; u < v; u++){
            for(int& v : adj[u]){
                indegree[v]++;
            }
        }
    }


public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // graph foramtion:
        vector<vector<int>> adj = adjFormation(V, edges);

        //indegree calculation
        vector<int> indegree(V,0);
        indeg(V, adj, indegree);

        vector<bool> visited(V, false);
        vector<int> result;

        queue<int> q;

        //push all zero indegree..
        for (int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //bfs code:
        while(!q.empty()){
            int temp = q.front();

            result.push_back(temp);
            q.pop();

            for(int& v : adj[temp]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }

        }

        return result;
    }
};

int main(){
    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 3}, {1, 2}, {3, 2}, {2, 5}, {3, 4}, {4, 5}};
    int V = 6;

    vector<int> result = sol.topoSort(V, edges);

    for (int &val : result)
    {
        cout << val << ' ';
    }

    return 0;
}