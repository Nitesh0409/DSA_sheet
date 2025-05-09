// question link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include<bits/stdc++.h>
using namespace std;

// althogh this is tougher version of greater element (stack) problem like but this is best question
// solve this again completely to revise 🤯

//approach: similar find left and right smaller element index , and then multiply that with height respectively.


class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        if (n == 1)
        {
            return heights[0] * n;
        }

        vector<int> result1(n, -1);
        vector<int> result2(n, n);

        stack<int> s1;
        stack<int> s2;

        for (int i = 0; i < n; i++)
        {
            while (!s1.empty() && heights[s1.top()] >= heights[i])
            {
                s1.pop();
            }

            if (!s1.empty())
            {
                result1[i] = s1.top();
            }

            s1.push(i);
        }

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s2.empty() && heights[s2.top()] >= heights[i])
            {
                s2.pop();
            }

            if (!s2.empty())
            {
                result2[i] = s2.top();
            }

            s2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, heights[i] * (result2[i] - result1[i] - 1));
        }
        return maxArea;
    }
};

int main()
{

    vector<int> arr = {2, 1, 5, 6, 2, 3};

    Solution sol;

    cout << sol.largestRectangleArea(arr) << endl;

    return 0;
}
