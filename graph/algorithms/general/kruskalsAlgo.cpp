#include<bits/stdc++.h>

using namespace std;

class Solution
{
    // vector<vector<pair<int,int>>> adj;   //u -> {v,w}
    vector<int> parent;
    vector<int> rank;

    void Dsu(int V)
    {
        parent.resize(V);
        rank.resize(V);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]); // compression
    }

    void unite(int x, int y)
    {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

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
            parent[py] = px;
            rank[px]++;
        }
    }

    static bool compareByWeight(const vector<int> &a, const vector<int> &b)
    {
        return a[2] < b[2];
    }

public:
    int kruskalsMST(int V, vector<vector<int>> &edges)
    {

        // sort in ascending weight
        sort(edges.begin(), edges.end(), compareByWeight);

        // dsu init
        Dsu(V);

        // kruskals logic
        int sum = 0;
        for (vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v)
            {
                unite(u, v);
                sum += w;
            }
        }

        return sum;
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
    int mstCost = sol.kruskalsMST(V, edges);

    cout << "Minimum cost of the MST: " << mstCost << endl;

    return 0;
}
