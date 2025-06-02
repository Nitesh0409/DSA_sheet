#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
    limitation of dijkstras: positive weights only

    we will update weight in resultant till (v-1) times only...
    if after that it changes this mean -ve weighted graph
*/

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src){
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int count = 1; count <= V-1; count++){
            for(vector<int>& edge : edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dist[u] != INT_MAX && dist[u]+ w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }
    
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, -2},
        {0, 3, 6},
        {1, 2, -3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};
    int src = 0;

    Solution sol;
    vector<int> shortestPaths = sol.bellmanFord(V, edges,src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < shortestPaths.size(); ++i)
    {
        cout << "Node " << i << ": " << shortestPaths[i] << endl;
    }

    return 0;
}
