#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Step 1: Enqueue all 0's and set distance = 0
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // Step 2: BFS from all 0's
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                {
                    if (dist[nx][ny] > dist[x][y] + 1)
                    {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};

//--------------------------------------------------------------------------------------

//this is brute force solution but not optimize ...to make this optimal use multisource bfs
class SolutionBrute
{
    void bfs(vector<vector<int>> &mat, vector<vector<int>> &nmt, int i, int j)
    {
        queue<pair<int, int>> q; //{i,j}
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({i, j});
        visited[i][j] = true;

        int count = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                q.pop();

                int posV = p.first;  // vertical position
                int posH = p.second; // horizontal position

                vector<pair<int, int>> direction = {{posV - 1, posH}, {posV + 1, posH}, {posV, posH - 1}, {posV, posH + 1}};

                for (pair<int, int> &points : direction)
                {
                    int v = points.first;
                    int h = points.second;

                    if ((v < m && v >= 0) && (h < n && h >= 0) && !visited[v][h])
                    {
                        if (mat[v][h] == 0)
                        {
                            nmt[i][j] = count;
                            return;
                        }
                        q.push({v, h});
                        visited[v][h] = true;
                    }
                }
            }
            count++;
        }
    }

public:
    // vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    // {
    //     int m = mat.size();
    //     int n = mat[0].size();

    //     vector<vector<int>> nmt(m, vector<int>(n, 0));

    //     // check for 1's nearest water and update
    //     for (int i = 0; i < m; i++)
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (mat[i][j] == 1)
    //             {
    //                 bfs(mat, nmt, i, j);
    //             }
    //         }
    //     }

    //     return nmt;
    // }
};

int main()
{
    // Example input grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};

    Solution sol;
    vector<vector<int>> result = sol.updateMatrix(grid);
    
    for(vector<int>& row : result){
        for(int& col : row){
            cout << col << " ";
        }
        cout << endl;
    }

    return 0;
}
