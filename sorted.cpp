#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // for brute force teqnique
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> result;
        for (int i : nums)
        {
            result.push_back(i * i);
        }
        sort(result.begin(), result.end());
        return result;
    }

    // for optimal :two pointer
    vector<int> sortedSquaresOpt(vector<int> arr){
        int first = 0;
        int last = arr.size() - 1;
        int pos = last;
        vector<int> result(arr.size());
        while( first <= last){
            int val1 = arr[first] * arr[first];
            int val2 = arr[last] * arr[last];
            if(val1 > val2){
                result[pos--] = val1;
                first++;
            }else{
                result[pos--] = val2;
                last--;
            }
        }
        return result;
    }
};

int main(){

    vector<int> arr;
    arr = {- 4, -1, 0, 3, 5};

    Solution sol;

    vector<int> result1 = sol.sortedSquares(arr);

    for(int i : result1){
        cout << i << " ";
    }
    cout << "\n";

    vector<int> result2 = sol.sortedSquaresOpt(arr);

    for (int i : result2)
    {
        cout << i << " ";
    }

    return 0;
}