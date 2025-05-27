#include <bits/stdc++.h>

using namespace std;

//just used kanhs algo if not possible to get all nodes that mean cycle exist 

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
        vector<vector<int>> adj = adjFormation(V, edges);

        //indegree formation
        vector<int> indegree(V);
        for (int i = 0; i < V; i++){
            for(int& v : adj[i]){
                indegree[v]++;
            }
        }

        
        //kanh's algo
        queue<int> q;
        for (int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;

            for(int&v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        return (count == V) ? false : true;
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