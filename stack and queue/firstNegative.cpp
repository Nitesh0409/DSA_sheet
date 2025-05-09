#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // brute force approach:
    /*
    first traverse k
    then find first negative value and print that else print 0;

    t => O(n*k), s => O(1);
    */
    vector<int> firstNegative_brute(vector<int> &arr, int k)
    {
        vector<int> result;
        int n = arr.size();

        for(int i = 0; i< n-k+1; i++){
            bool findNeg = false;
            for(int j = i; j < k+i; j++){
                if(arr[j] < 0){
                    result.push_back(arr[j]);
                    findNeg = true;
                    break;
                }
            }
            if(!findNeg){
                result.push_back(0);
            }

        }
        return result;
    }

    // there is one solution with window sliding , t => O(n) and s => O(n);

    vector<int> firstNegative_opt(vector<int> arr, int k){
        vector<int> result;
        deque<int> dq;

        int n = arr.size();

        for (int i = 0; i < k; i++)
        { // window formation and putting all neg ints
            if (arr[i] < 0)
            {
                dq.push_back(i);
            }
        }

        for (int i = k; i < n; i++)
        {
            result.push_back(dq.empty() ? 0 : arr[dq.front()]);

            while(!dq.empty() && dq.front() <= i-k ){
                dq.pop_back();
            }

            if (arr[i] < 0)
            {
                dq.push_back(i);
            }
        }

        result.push_back(dq.empty() ? 0 : arr[dq.front()]);

        return result;
    }


    //more optimal without deque :
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        vector<int> result;
        int n = arr.size();
        int firstNegIndex = 0; // index of the first negative in current window

        for (int i = k - 1; i < n; ++i)
        {
            // Move firstNegIndex to current window
            while (firstNegIndex < i &&
                   (firstNegIndex <= i - k || arr[firstNegIndex] >= 0))
            {
                firstNegIndex++;
            }

            if (arr[firstNegIndex] < 0 && firstNegIndex <= i)
            {
                result.push_back(arr[firstNegIndex]);
            }
            else
            {
                result.push_back(0);
            }
        }

        return result;
    }
};

int main(){

    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;

    Solution sol;

    vector<int> result = sol.firstNegative_brute(arr, k);

    for(int val : result){
        cout << val << " ";
    }

    return 0;
}