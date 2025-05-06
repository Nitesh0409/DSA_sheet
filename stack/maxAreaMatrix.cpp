#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();
        int maxAreafinal = 0;

        vector<int> heights(col, 0);

        for (int j = 0; j < row; j++){

            for (int i = 0; i < col; i++)
            {
                if (matrix[j][i] == '1')
                    heights[i] += 1;
                else
                    heights[i] = 0;
            }

            vector<int> ls(col, -1);
            vector<int> rs(col, col);

            stack<int> stL;
            stack<int> stR;

            for (int i = col - 1; i >= 0; --i)
            {
                while (!stR.empty() && heights[stR.top()] >= heights[i])
                {
                    stR.pop();
                }

                if (!stR.empty())
                {
                    rs[i] = stR.top();
                }

                stR.push(i);
            }

            for (int i = 0; i < col; i++)
            {
                while (!stL.empty() && heights[stL.top()] >= heights[i])
                {
                    stL.pop();
                }

                if (!stL.empty())
                {
                    ls[i] = stL.top();
                }

                stL.push(i);
            }

            int maxArea = 0;
            for (int i = 0; i < col; i++)
            {
                maxArea = max(maxArea, heights[i] * (rs[i] - ls[i] - 1));
            }
            maxAreafinal = max(maxAreafinal, maxArea);
        }
        return maxAreafinal;
    }
};

int main(){

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    Solution sol;
    cout<<sol.maximalRectangle(matrix)<<endl;

    return 0;
}