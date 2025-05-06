#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    // this is brute force approach => basically traverse array and find next greater element;
    // t => O(n^2); s => O(n);
    vector<int> nextGreaterElement_brute(vector<int> arr){
        int n = arr.size();
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    result[i] = arr[j];
                    break;
                }
            }
        }

        return result;
    }


    //this is optimization => using stack
    /* basically start from last and use following rule to fill result:
        1. if stack empty, put index value = -1;
        2. otherwise check top element of stack , is it smaller then arr[i] then just pop out it , 
            if not then just put this top val in result and push arr[i] in stack
    */

    // t => O(n), s => O(n)

    vector<int> nextGreaterElement_opt(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = n - 1; i >= 0; i--)
        {
            // pop out if smaller
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }

            // if not empty and not smaller then put val in result
            if (!s.empty())
            {
                result[i] = s.top();
            }

            // push current element
            s.push(arr[i]);
        }
        return result;
    }

    // sometime question is on circular array and we have to find next greater then
    // just first put all values of values in ascendig order in stack and then start applying earlier logic.
    vector<int> nextGreaterElement_circular(vector<int> &nums)
    {
        int n = nums.size();

        stack<int> s;
        vector<int> result(n, -1);

        for (int i = 2 * n - 1; i >= 0; --i)
        {
            int curr = nums[i % n];

            while (!s.empty() && s.top() <= curr)
            {
                s.pop();
            }

            if (i < n)
            {
                result[i] = s.empty() ? -1 : s.top();
            }

            s.push(curr);
        }
        return result;
    }
};

int main(){

    vector<int> arr = {6, 8, 0, 1, 3};

    Solution sol;
    vector<int>result = sol.nextGreaterElement_circular(arr);

    for(int val : result){
        cout << val<<" ";
    }

    return 0;
}