#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
    Dijkstra's Algorithm:
    Finds the shortest path from a source node to all other nodes
    in a weighted graph with non-negative edge weights.

    basically simple bfs by using mean heap
*/

class Solution
{
    vector<vector<pair<int, int>>> adj;

    void graphFormation(int V, vector<vector<int>> &edges)
    {
        adj.resize(V);
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
    }

public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        graphFormation(V, edges); // graph formation => {u->{v,w}} : where u-> source, v-> destination, w-> weight

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //mean heap
        vector<int> result(V, INT_MAX);    //to store resultant distance

        pq.push({0, src});
        result[src] = 0;

        while (!pq.empty())
        {
            pair<int, int> p = pq.top();
            pq.pop();

            int weight = p.first;
            int node = p.second;

            for (pair<int, int> &nbrPair : adj[node])
            {
                int nbr = nbrPair.first;
                int w = nbrPair.second;

                int newWeight = result[node] + w;

                if (newWeight < result[nbr])
                {
                    pq.push({newWeight, nbr});
                    result[nbr] = newWeight;
                }
            }
        }

        return result;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}};
    int src = 0;

    Solution sol;
    vector<int> shortestPaths = sol.dijkstra(V, edges, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < shortestPaths.size(); ++i)
    {
        cout << "Node " << i << ": " << shortestPaths[i] << endl;
    }

    return 0;
}
