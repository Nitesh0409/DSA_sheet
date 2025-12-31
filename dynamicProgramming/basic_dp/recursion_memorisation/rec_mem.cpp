#include<bits/stdc++.h>

using namespace std;

//basic idea:
/*
    first write simple recursion solution with return something acc. to base
    then do memorisation
*/

class Solution{
public:
    // -----------------------------recursive solution -> t = O(2^N) ----------------
    int recursion_fibonacci(int n){
        //base cond.
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        //recursive
        return recursion_fibonacci(n - 1) + recursion_fibonacci(n - 2);
    }


    //-----------------------------now add memorisation -> t = O(N)------------------------------------

    int dp[10000]; //size depends on constraints

    int fib(int n){
        // base cond.
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        
        //check already exisit in memory
        if(dp[n] != -1)
            return dp[n];

        // recursive
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    int rec_mem_fibonacci(int n){
        memset(dp, -1, sizeof(dp));

        return fib(n);
    }

};

int main(){
    int n;
    cout << "input position : ";
    cin >> n;

    Solution sol;
    //-------recursion solution calling-----------------
    cout <<"recursive sol : "<< sol.recursion_fibonacci(n) << endl;

    //------- recursion + memorisation--------------------
    cout <<"recusion + memorisation sol : " << sol.rec_mem_fibonacci(n) << endl;

    return 0;
}