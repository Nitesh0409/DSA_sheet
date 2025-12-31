#include <bits/stdc++.h>

using namespace std;

//idea:
/*
    Solve smallest problems first, build up to the answer 
    also just play play with n to i  (not true for each solution)
*/

class Solution
{
public:
    //-----------------------------recursion + memorisation -> t = O(N)------------------------------------

    int dp[10000 + 1]; // size depends on constraints

    int fib(int n)
    {
        // base cond.
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // check already exisit in memory
        if (dp[n] != -1)
            return dp[n];

        // recursive
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    int rec_mem_fibonacci(int n)
    {
        memset(dp, -1, sizeof(dp));

        return fib(n);
    }

    //-----------------------------bottom up -> t = O(N)------------------------------------

    int bottom_up_fibonacci(int n){
        vector<int> t(n+1);

        t[0] = 0;
        t[1] = 1;

        if(n < 2)
            return n;

        for (int i = 2; i <= n; i++){
            t[i] = t[i - 1] + t[i - 2];
        }

        return t[n];
    }

};

int main()
{
    int n;
    cout << "input position : ";
    cin >> n;

    Solution sol;
    //------- recursion + memorisation--------------------
    cout << "recusion + memorisation sol : " << sol.rec_mem_fibonacci(n) << endl;

    //------ bottom up ------------------------------------
    cout << "bottom up sol : " << sol.bottom_up_fibonacci(n) << endl;

    return 0;
}