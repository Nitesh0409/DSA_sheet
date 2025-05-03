#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

//-----------brute forcc approach : rotate every time , t = O(n*k), space = O(1)----------------
    void rotate_brute(vector<int> &nums, int k){
        int n = nums.size();
        k %= n; // exact no. of rotation

        for(int i = 0; i < k; i++){
            int last = nums[n - 1];
            for (int j = n - 1; j > 0; --j){
                nums[j] = nums[j - 1];
            }
            nums[0] = last;
        };
    }

//------------optimize : just making rotated solution, t = O(n), s = O(n)-----------
    // nums = [ 1, 2, 3, 4, 5 ]; and k =2
    // rots = [ 4, 5, 1, 2, 3 ];  so rots[(i+k)%n] = nums[i]

    void rotate_opt1(vector<int>& nums, int k){
        int n = nums.size();
        k %= n;

        vector<int> result(n);
        for (int i = 0; i < n; i++){
            result[(i + k) % n] = nums[i];
        }
        nums = result;
    }


//---------best approach t = O(n), s = O(1)------------------
    //let k =2 and nums = [1,2,3,4,5]
    //r1 = [5,4,3,2,1]
    //r2 = [4,5,3,2,1]  rotate till K'th
    //r3 = [4,5,1,2,3]  rotate remaining.

    void rotate_opt2(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(){

    vector<int> nums = { 1, 2, 3, 4, 5};
    int k = 2;

    Solution sol;
    // sol.rotate_brute(nums, k);
    // sol.rotate_opt1(nums, k);
    sol.rotate_opt2(nums, k);

    for (int num : nums)
        cout << num << " "; // Output: 4,5,1,2,3

    return 0;
}