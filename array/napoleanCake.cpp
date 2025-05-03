#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

//---------brute force : basically start in end and put 1's till value of cream--------
//---------t = O(n^2), s = O(n) ------------------

    vector<int> napoleanCake_brute(vector<int> arr){
        int n = arr.size();
        vector<int> result(n);
        int i = n - 1;
        while(i >= 0 ){
            if(arr[i] != 0 && i >= 0){
                int cream = arr[i];
                while((cream--) && i >= 0){
                    result[i] = 1;
                    i--;
                    if(arr[i] != 0){
                        cream = max(cream, arr[i]);
                    }
                }
            }
            i--;
        }
            return result;
    };


//----------most optimize --------as we check value of cream at every layer, t = O(n) and s = s(n)
    vector<int> napoleanCake_opt(vector<int> arr)
    {
        int n = arr.size();
        vector<int> result(n,0);
        int cream = 0;
        for (int i = n - 1; i >= 0; --i){
            cream = max(cream, arr[i]);
            if(cream > 0){
                result[i] = 1;
            }
            cream = max(0, cream - 1);
        }

        return result;
    }
};

int main(){
    vector<int> arr = {0,0,0,1,0,5,0,0,0,2};

    Solution sol;
    vector<int> result = sol.napoleanCake_opt(arr);

    for(int i : result){
        cout << i << " ";
    }

    return 0;
}