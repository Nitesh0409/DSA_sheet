#include<bits/stdc++.h>

using namespace std;

/*
    Prim's Algorithm:
    Finds the Minimum Spanning Tree (MST) for a connected weighted undirected graph.

    this is looks like dijkstras algo with some modification

*/

class Solution
{
public:
    int primMST(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) // graph formation   => {src -> {dest,wt}};
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<bool> inMST(V, false);   //visited
        vector<int> key(V, INT_MAX); // Cost to add each node to MST  same as distance vector
        key[0] = 0;
        pq.push({0, 0});

        int mstWeight = 0;

        while (!pq.empty())
        {
            auto [weight, node] = pq.top();
            pq.pop();

            if (inMST[node])
                continue;

            inMST[node] = true;
            mstWeight += weight;

            for (auto &[nbr, wt] : adj[node])
            {
                if (!inMST[nbr] && wt < key[nbr])
                {
                    key[nbr] = wt;
                    pq.push({wt, nbr});
                }
            }
        }

        return mstWeight;
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

    Solution sol;
    int mstCost = sol.primMST(V, edges);

    cout << "Minimum cost of the MST: " << mstCost << endl;

    return 0;
}
