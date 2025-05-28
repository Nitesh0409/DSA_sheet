#include <iostream>
#include <vector>
using namespace std;

//this algo will not work for directed graph

class Solution
{
    vector<vector<int>> adj;
    vector<int> parent;
    vector<int> rank;

    void graphFormation(int V, vector<vector<int>> &edges)
    {
        adj.clear();
        adj.resize(V);

        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void init(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
        {
            return;
        }

        if (rank[px] < rank[py])
        {
            parent[px] = py;
        }
        else if (rank[px] > rank[py])
        {
            parent[py] = px;
        }
        else
        {
            parent[px] = py;
            rank[py]++;
        }
    }

public:
    bool containsCycle(int V, vector<vector<int>> &edges)
    {

        graphFormation(V, edges);

        init(V);

        // vector<int>visited(V,false);

        for (int u = 0; u < V; u++)
        {
            for (int &v : adj[u])
            {
                if (u < v)
                {
                    int pu = find(u);
                    int pv = find(v);
                    if (pu == pv)
                    {
                        return true;
                    }

                    unite(u, v);
                }
            }
        }
        return false;
    }
};

// ---------------------- MAIN FUNCTION FOR TESTING ----------------------
int main()
{
    Solution sol;

    // Test Case 1: No cycle
    int V1 = 5;
    vector<vector<int>> edges1 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4}};
    cout << "Test Case 1: ";
    cout << (sol.containsCycle(V1, edges1) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 2: Cycle exists (4 -> 0 connects back)
    int V2 = 5;
    vector<vector<int>> edges2 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 0}};
    cout << "Test Case 2: ";
    cout << (sol.containsCycle(V2, edges2) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 3: Disconnected graph with one component containing a cycle
    int V3 = 6;
    vector<vector<int>> edges3 = {
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 4}};
    cout << "Test Case 3: ";
    cout << (sol.containsCycle(V3, edges3) ? "Cycle Detected" : "No Cycle") << endl;

    // Test Case 4: Multiple components, no cycle
    int V4 = 6;
    vector<vector<int>> edges4 = {
        {0, 1},
        {2, 3},
        {4, 5}};
    cout << "Test Case 4: ";
    cout << (sol.containsCycle(V4, edges4) ? "Cycle Detected" : "No Cycle") << endl;

    return 0;
}
