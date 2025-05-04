// question link: https://leetcode.com/problems/maximum-product-of-three-numbers/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // brute force : first sort then just multipy last three, or {first two and last (to make +ve value)}

    int maxProduct_brute(vector<int>& nums){
        int n = nums.size();
        sort(nums.begin(), nums.end());

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }


    //best and new approach 😉 
    
    int maxProduct_opt(vector<int>& nums){
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int num : nums)
        {
            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
            {
                max3 = num;
            }

            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min2 = num;
            }
        }

        return max(max1 * max2 * max3, min1 * min2 * max1);
    }
};


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};

    Solution sol;
    int result = sol.maxProduct_opt(arr);

    cout << result << endl;

    return 0;
}