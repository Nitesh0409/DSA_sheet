// question link : https : // leetcode.com/problems/majority-element/description/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    // brute force : just check every element and count appearence, if greater then n/2..solution
    // t => O(n^2), s => O(1)
    int majorityElement_brute(vector<int> nums){
        int n = nums.size();

        int maxCount = 0;
        int result = 0;
        for (int i = 0; i < n; i++){
            int count = 0;
            for (int j = 0; j < n; j++){
                if(nums[j] == nums[i]){
                    count++;
                }
            }
            if(count > maxCount){
                result = nums[i];
                maxCount = count;
            }
            if(maxCount > n/2){
                return result;
            }
        }
        return -1;
    }

    // better optimization : using hashmap  , t => O(n), s => O(n)
    int majorityElement_opt1(const vector<int> &nums)
    {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums)
        {
            freq[num]++;
            if (freq[num] > n / 2)
            {
                return num;
            }
        }

        return -1; // for no majority
    }


    //the best optimization : using MOORE'S VOTING ALGORITHM, t => O(N), S => O(1)
    int majorityElement_opt2(vector<int> &nums)
    {
        int count = 0;
        int candidate = 0;

        for (int num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main(){

    vector<int> arr = {2, 2, 1, 1, 2, 2};

    Solution sol;
    int value1 = sol.majorityElement_brute(arr);
    int value2 = sol.majorityElement_opt1(arr);
    int value3 = sol.majorityElement_opt2(arr);

    cout << value1 << "\n"
         << value2 << "\n"
         << value3 << "\n"
         << endl;

    return 0;
}