#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> digitToVector(int digit){
        vector<int> nums;
        while(digit > 0){
            int s = digit % 10;
            digit /= 10;
            nums.push_back(s);
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }

    //brute force : generating all permutation, t = O(n!), s = O(n)
    int nextGreaterElement_brute(int digit) {
        // will do later

        return 0;
    };


    // optimize way : lexicographical or next greater element algorithm , t = O(n), s = O(n)

    // we are going to do following,
    // first start from end and  find dip (decreasing point) then swap it with rhs value which is just 
    // greater then dip's value,
    // and then just reverse rhs

    int nextGreaterElement_opt(int digit){
        vector<int> arr = digitToVector(digit);
        int n = arr.size();

        int i = n - 2;
        while (i >= 0 && (arr[i] >= arr[i+1])){
            i--;
        }

        if(i == -1){
            return -1;
        }

        int j = n - 1;
        while(j > i && (arr[j] <= arr[i])){
            j--;
        }

        swap(arr[i], arr[j]);

        reverse(arr.begin() + i+ 1, arr.end());

        long long result = 0;
        for( int value : arr){
            result = result * 10 + value;            //nice strategy 😉
        }

        return result;
    }

};

int main(){

    int digit = 342543;

    Solution sol;
    int result = sol.nextGreaterElement_opt(digit);

    cout << result << endl;

    return 0;
}