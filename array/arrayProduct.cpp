// question link : https : // leetcode.com/problems/product-of-array-except-self/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    // this is brute force {basically multiply each no except itself } , t = O(n^2), s= O(n)
    vector<int> arrayProduct_brute(vector<int> arr){
        int n = arr.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++){
            int mul = 1;
            for (int j = 0; j < n; j++){
                if(i != j){
                    mul *= arr[j];
                }
            }
            result[i] = mul;
        }
        return result;
    }

    // best approach: new method ;  t => O(n), s => O(n);
    vector<int> arrayProduct_opt(vector<int> arr){
        int n = arr.size();
        vector<int> result(n);

        int left = 1;
        for (int i = 0; i < n; i++){
            result[i] = left;
            left *= arr[i];
        }

        int right = 1;
        for (int j = n-1; j >= 0; --j){
            result[j] *= right;
            right *= arr[j];
        }
        return result;
    }
};

int main(){

    vector<int> arr = {1, 2, 3, 4};

    Solution sol;
    vector<int> result = sol.arrayProduct_opt(arr);

    for(int i: result){
        cout << i << " ";
    }
    return 0;
}