// question link: https://leetcode.com/problems/max-chunks-to-make-sorted-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // for brute force : like first merge them by merge and while merging find no. of split.

    //best approach => just check vlaue matches with sorted array if yes increase count 🤩

    int maxChunksToSorted(vector<int> &arr)
    {
        vector<int> copyArr = arr;
        sort(copyArr.begin(), copyArr.end());

        int count = 0;
        int maxVal = INT_MIN;
        for (int i = 0; i < arr.size(); i++)
        {
            maxVal = max(maxVal, arr[i]);
            if (maxVal == copyArr[i])
            {
                count++;
            }
        }
        return count;
    }
};


int main(){
    vector<int> arr = {2, 1, 3, 4, 4};

    Solution sol;
    int value = sol.maxChunksToSorted(arr);

    cout << value << endl;

    return 0;
}