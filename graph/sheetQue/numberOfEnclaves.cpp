#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;


class Solution
{

    void dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i >= m ||i < 0 || j >= n || j < 0 ||grid[i][j] == 0){
            return;
        }

        grid[i][j] = 0;

        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        // remove all 1's related to boundary
        for (int i = 0; i < m; i++){
            if(grid[i][0] == 1)
                dfs(grid, i, 0);
            
            if(grid[i][n-1] == 1)
                dfs(grid, i, n - 1);
        }

        for (int i = 0; i < n; i++){
            if(grid[0][i] == 1)
                dfs(grid, 0, i);
            if(grid[m-1][i] == 1)
                dfs(grid, m - 1, i);
        }

        //count number of 1's in matrix
        int count = 0;
        for (int i = 0; i< m; i++){
            for (int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
};



//---------------------------------------------------------------------------------
// this is my approach very bad 😥
struct hash_pair
{
    size_t operator()(const pair<int, int> &p) const
    {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};
class SolutionGeneral

// this is my method of solving not best...
{
    vector<int> parent;
    vector<int> rank;
    unordered_map<int, pair<int, int>> idToCoord;            // id -> (i,j)
    unordered_map<pair<int, int>, int, hash_pair> coordToId; // (i,j) -> id

    void DSU(int totalOne)
    {
        rank.resize(totalOne, 0);
        parent.resize(totalOne);
        for (int i = 0; i < totalOne; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
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
            parent[px] = py;
            rank[py]++;
        }
    }

    int countOne(vector<vector<int>> &grid)
    {
        int nodes = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    coordToId[{i, j}] = nodes;
                    idToCoord[nodes] = {i, j};
                    nodes++;
                }
            }
        }
        return nodes;
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int totalOne = countOne(grid);
        DSU(totalOne);

        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        // Union adjacent lands
        for (auto &entry : coordToId)
        {
            int i = entry.first.first;
            int j = entry.first.second;
            int id1 = entry.second;

            for (auto &dir : dirs)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1)
                {
                    int id2 = coordToId[{ni, nj}];
                    unite(id1, id2);
                }
            }
        }

        // Find all parents of land cells that touch the boundary
        unordered_set<int> boundaryParents;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                    {
                        int id = coordToId[{i, j}];
                        boundaryParents.insert(find(id));
                    }
                }
            }
        }

        // Count all non-boundary-connected land cells
        int result = 0;
        for (auto &entry : coordToId)
        {
            int id = entry.second;
            if (boundaryParents.find(find(id)) == boundaryParents.end())
            {
                result++;
            }
        }

        return result;
    }
};

// ---------------------------------------------------------------------------------------------

int main()
{
    // Example input grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution sol;
    int result = sol.numEnclaves(grid);

    cout << "Number of enclaved land cells: " << result << endl;

    return 0;
}
