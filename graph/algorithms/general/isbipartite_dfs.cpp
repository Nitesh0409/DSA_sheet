#include<bits/stdc++.h>

using namespace std;

//this is dfs traversal just make sure color are different

class Solution
{
    bool dfs(vector<vector<int>> &graph, vector<int> &color, int u, int c)
    {
        color[u] = c;

        for (int &v : graph[u])
        {
            if (color[v] == -1)
            {
                if (!dfs(graph, color, v, 1 - c))
                    return false;
            }
            else
            {
                if (c == color[v])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1 && !dfs(graph, color, i, 0))
                return false;
        }

        return true;
    }
};

int main()
{
    // Example 1: Bipartite graph
    vector<vector<int>> graph1 = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    // Example 2: Non-bipartite graph
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}};

    Solution solution;

    cout << "Graph 1 is " << (solution.isBipartite(graph1) ? "Bipartite" : "Not Bipartite") << endl;
    cout << "Graph 2 is " << (solution.isBipartite(graph2) ? "Bipartite" : "Not Bipartite") << endl;

    return 0;
}