// question link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // this is efficient code ...i will write intution later

    vector<vector<int>> tree;
    vector<int> res, count;

    void postOrder(int node, int parent)
    {
        for (int child : tree[node])
        {
            if (child == parent)
                continue;
            postOrder(child, node);
            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }

    void preOrder(int node, int parent, int n)
    {
        for (int child : tree[node])
        {
            if (child == parent)
                continue;
            res[child] = res[node] - count[child] + (n - count[child]);
            preOrder(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        tree = vector<vector<int>>(n);
        res = vector<int>(n, 0);
        count = vector<int>(n, 1); // Each node counts as 1

        // Build adjacency list
        for (auto &edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // First DFS from root (node 0)
        postOrder(0, -1);

        // Second DFS to update answers for all nodes
        preOrder(0, -1, n);

        return res;
    }
};

class Solution2
{
public:
    // approach 1 : complete by me only 🤩 but this is not effcient  t => O(n^2);
    vector<vector<int>> graphFormation(int n, vector<vector<int>> edges)
    {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        return graph;
    }

    void distance(int node, int &maxSum, int sum, vector<vector<int>> &graph, vector<bool> &visited)
    {
        if (visited[node])
            return;

        visited[node] = true;
        sum++;
        maxSum += (sum - 1);

        for (int neighbor : graph[node])
        {
            distance(neighbor, maxSum, sum, graph, visited);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph = graphFormation(n, edges);
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            int sum = 0, maxSum = 0;
            vector<bool> visited(n, false);
            distance(i, maxSum, sum, graph, visited);
            result.push_back(maxSum);
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    int n = 6;

    Solution1 sol;

    vector<int> result = sol.sumOfDistancesInTree(n, edges);

    for(int val: result){
        cout << val << " ";
    }

    return 0;
}