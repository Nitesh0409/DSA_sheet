#include<bits/stdc++.h>

using namespace std;

// que link: https://leetcode.com/problems/number-of-digit-one/description/
/*
    count no of 1 in range
    idea:
        states :
        idx, tight (common for all digit dp)
        end_of_1 => count no. of 1 -> increase if we choose digit == 1;

*/

class Solution
{
    int dp[10][2][10];
    int solve(string &s, int idx, bool tight, int end_of_1)
    {
        if (idx == s.size())
        {
            return end_of_1;
        }

        if (dp[idx][tight][end_of_1] != -1)
            return dp[idx][tight][end_of_1];

        int lb = 0;
        int ub = (tight == false) ? 9 : s[idx] - '0';

        int res = 0;
        for (int dig = lb; dig <= ub; dig++)
        {
            res += solve(s, idx + 1, (tight && (dig == ub)), end_of_1 + (dig == 1));
        }

        return dp[idx][tight][end_of_1] = res;
    }

public:
    int countDigitOne(int n)
    {
        string v = to_string(n);

        memset(dp, -1, sizeof(dp));
        return solve(v, 0, true, 0);
    }
};


int main(){
    int n;
    cout << "enter n: ";
    cin >> n;

    Solution sol;

    cout << "res : " << sol.countDigitOne(n)<<endl;
    return 0;
}