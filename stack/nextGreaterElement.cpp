// Que - 1 : https : // www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Que - 2 : https://leetcode.com/problems/next-greater-element-ii/description/
// Que - 3 : https://leetcode.com/problems/daily-temperatures/
// Que - 4 : https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Que - 5 : https : // www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/


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

//-----------------------------------------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------------------------------------

    //smaller variation of this question:
    // here we have to return only difference of index of day for warmer day then current
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> s;

        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                result[i] = s.top() - i;
            }

            s.push(i);
        }
        return result;
    }


//-----------------------------------------------------------------------------------------------------------

    //🤯this is good variation of this ...so solve again.
    //we have to return no. of continuos day for for which span is less then current.
    vector<int> calculateSpan(vector<int> &arr)
    {
        // write code here
        int n = arr.size();

        vector<int> result(n,1);

        stack<int>s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] <= arr[i])
            {
                s.pop();
            }

            if (!s.empty())
            {
                result[i] = i - s.top();
            }
            else
            {
                result[i] = i+1;
            }

            s.push(i);
        }
        return result;
    }

//-----------------------------------------------------------------------------------------------------------

    // good varition: basically we have to return max difference minimum value left and right of a index val
    int maxDifference(vector<int> &arr)
    {
        // write code here
        int n = arr.size();

        vector<int> result1(n, 0);
        vector<int> result2(n, 0);

        stack<int> s1;
        stack<int> s2;

        for (int i = 0; i < n; i++)
        {
            while (!s1.empty() && s1.top() >= arr[i])
            {
                s1.pop();
            }

            if (!s1.empty())
            {
                result1[i] = s1.top();
            }

            s1.push(arr[i]);
        }

        for (int i = n-1; i >= 0; --i)
        {
            while (!s2.empty() && s2.top() >= arr[i])
            {
                s2.pop();
            }

            if (!s2.empty())
            {
                result2[i] = s2.top();
            }

            s2.push(arr[i]);
        }

        int maxDiff = 0;
        for (int i = 0; i < n; i++)
        {
            maxDiff = max(maxDiff, abs(result1[i] - result2[i]));
        }
        return maxDiff;
    }

};

int main(){

    vector<int> arr = {2, 4, 8, 7, 7, 9, 3};

    Solution sol;
    vector<int>result = sol.calculateSpan(arr);

    for(int val : result){
        cout << val<<" ";
    }

    // cout << sol.maxDifference(arr) << endl;

    return 0;
}