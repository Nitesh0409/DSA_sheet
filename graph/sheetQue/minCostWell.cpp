/*
Problem: Minimum Cost to Supply Water to All Homes

You are given `n` houses labeled from 1 to n.

There are two ways to supply water to each house:
1. Build a well in that house.
2. Connect it to another house with a pipeline. If one house has water, the connected one gets water too.

Each house must have access to water, either by having its own well or being connected to another house that does.

Input:
- An integer `n` representing number of houses.
- A vector `wells` of size n, where wells[i] is the cost to build a well in house (i + 1).
- A list of `pipes` where each pipe is represented by 3 integers: [house1, house2, cost].

Output:
- Return the minimum total cost to supply water to all houses.

Example 1:
Input:
n = 3
wells = [1, 2, 2]
pipes = {{1, 2, 1}, {2, 3, 1}, {1, 3, 2}}

Output:
3

Explanation:
- Build a well in house 1 (cost = 1)
- Connect house 2 to house 1 via pipe (cost = 1)
- Connect house 3 to house 2 via pipe (cost = 1)
Total cost = 1 + 1 + 1 = 3

Approach:
- Model this as a graph with an extra virtual node (node 0)
- Connect node 0 to every house with the cost of building a well
- Add all pipes as edges
- Apply Kruskal's algorithm to find Minimum Spanning Tree
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    vector<int> parent;
    vector<int> rank;

    void Dsu(int V)
    {
        parent.resize(V);
        rank.resize(V);
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]); // Path compression
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
    int minCostToSupplyWater(int n, vector<int> wells, vector<vector<int>> &pipes)
    {
        vector<vector<int>> completeEdges = pipes;
        for (int i = 0; i < n; i++)
        {
            completeEdges.push_back({0, i + 1, wells[i]});
        }
        sort(completeEdges.begin(), completeEdges.end(), compareByWeight);

        Dsu(n + 1); // <-- FIX: DSU for n+1 nodes (including virtual node 0)

        int sum = 0;
        for (vector<int> &edge : completeEdges)
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

// Test cases
int main()
{
    Solution sol;

    // Test Case 1
    int n1 = 3;
    vector<int> wells1 = {1, 2, 2};
    vector<vector<int>> pipes1 = {{1, 2, 1}, {2, 3, 1}, {1, 3, 2}};
    cout << "Test Case 1 Output: " << sol.minCostToSupplyWater(n1, wells1, pipes1) << endl; // Expected: 3

    // Test Case 2
    int n2 = 2;
    vector<int> wells2 = {5, 3};
    vector<vector<int>> pipes2 = {{1, 2, 1}};
    cout << "Test Case 2 Output: " << sol.minCostToSupplyWater(n2, wells2, pipes2) << endl; // Expected: 4

    // Test Case 3
    int n3 = 4;
    vector<int> wells3 = {1, 1, 1, 1};
    vector<vector<int>> pipes3 = {{1, 2, 100}, {2, 3, 100}, {3, 4, 100}};
    cout << "Test Case 3 Output: " << sol.minCostToSupplyWater(n3, wells3, pipes3) << endl; // Expected: 4

    return 0;
}
