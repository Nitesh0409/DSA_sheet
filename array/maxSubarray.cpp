// question link : https : // leetcode.com/problems/maximum-subarray/description/

#include<bits/stdc++.h>
                        using namespace std;

class Solution{
public:
    // brute force : just make all permutation and check max sum and return;

    //better approach: 

    //  basic kaden algorithm

    int maxSubarray_sum(vector<int> arr)
    {
        int n = arr.size();

        int maxSum = INT_MIN;
        int sum = 0;

        int i = 0;
        while (i < n)
        {
            sum = max(sum + arr[i], arr[i]);
            maxSum = max(sum, maxSum);
            i++;
        }

        return maxSum;
    }

    vector<int> maxSubarray(vector<int> arr)
    {
        vector<int> result;
        int n = arr.size();

        int maxSum = arr[0];
        int currentSum = arr[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < n; ++i)
        {
            if (currentSum < 0)
            {
                currentSum = arr[i];
                tempStart = i;
            }
            else
            {
                currentSum += arr[i];
            }

            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                start = tempStart;
                end = i;
            }
        }

        result.push_back(start);
        result.push_back(end);
        result.push_back(maxSum);
        return result;
    }


};

int main(){
    vector<int> arr = {7, -1, -6, 4, -5, 3};

    Solution sol;

    cout << sol.maxSubarray_sum(arr);

    vector<int> result = sol.maxSubarray(arr);

    for(int i: result){
        cout << i << " ";
    }

    return 0;
}