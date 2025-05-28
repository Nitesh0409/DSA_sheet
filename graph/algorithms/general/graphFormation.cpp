#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> adjFormation(int v, vector<vector<int>> & edges){
        vector<vector<int>> adj(v);

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // for undirected graph
        }

        return adj;
    }

};

int main(){
    Solution sol;

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}, {2, 4}};
    int V = 5;

    // by adj list
    vector<vector<int>> adj = sol.adjFormation(V, edges);

    int i = 0;
    for(vector<int> node : adj){
        cout << "node " <<i++<<" : ";
        for(int nodeVal : node){
            cout << nodeVal << " ";
        }
        cout << endl;
    }

    return 0;
}