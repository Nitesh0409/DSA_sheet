// question link: https://leetcode.com/problems/max-chunks-to-make-sorted/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // brute force approach to find split after doing actual spliting

    //best approach would be like we can just check whether index match with value or not, if match increase count. 

    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        int maxVal = -1;
        for (int i = 0; i < n; i++)
        {
            maxVal = max(maxVal, arr[i]);
            if (maxVal == i)
            {
                count++;
            }
        }
        return count;
    }
};


int main()
{
    vector<int> arr = {2, 1, 3, 4, 5};

    Solution sol;
    int value = sol.maxChunksToSorted(arr);

    cout << value << endl;

    return 0;
}