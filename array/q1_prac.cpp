// Problem: https://leetcode.com/problems/maximum-subarray/

// Difficulty: Medium
// Tags: Array, Kadane, DP

#include <bits/stdc++.h>
using namespace std;

// Brute Force - O(n^2)
int maxSubArrayBrute(vector<int>& nums) {
    int maxSum = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimized - Kadane’s Algorithm - O(n)
int maxSubArrayKadane(vector<int>& nums) {
    int currSum = nums[0], maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

// Dry Run Example:
// Input: [-2,1,-3,4,-1,2,1,-5,4]
// Brute Force: Check all subarrays
// Kadane: Keep track of maxSum and currSum

int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Brute: " << maxSubArrayBrute(arr) << endl;
    cout << "Kadane: " << maxSubArrayKadane(arr) << endl;
}

