#include<bits/stdc++.h>
using namespace std;

/*
    find total no. of integer between low to high 
        -> no two consecutive digit have same integer like: 12445 -> not valid (two 4 consecutive)
*/

class Solution{
    /*
    s -> string form range (0 - n)
    idx -> index
    tight -> tell whether constraints on digit choose btween 0-9
    prev -> tell previous value
    lead_zero -> avoid lead zero
    */
   
    int solve(string& s, int idx, bool tight, int prev, bool lead_zero){
        if(idx == s.size()){
            return 1;
        }

        int lb = 0; //lower bound
        int ub = (tight == 0) ? 9 : (s[idx] - '0'); //upper bound

        int res = 0;
        for (int dig = lb; dig <= ub; dig++){
            //invalid case
            if(dig == prev && !lead_zero)
                continue;
            
            // if(dig == 0){
            //     res += solve(s, idx + 1, false, dig, lead_zero);
            // }
            // else if(dig == ub){
            //     res += solve(s, idx + 1, true, dig, false);
            // }
            // else{
            //     res += solve(s, idx + 1, false, dig, false);
            // }

            res += solve(s, idx + 1, (dig == ub && tight), dig, (lead_zero && dig == 0));  //efficient way
        }
        return res;
    }
public:
    int totalInteger(int low, int high){
        string l = to_string(low-1);
        string h = to_string(high);

        if(low == 0)
            return solve(h, 0, true, 10, true);

        return solve(h,0,true,10,1) - solve(l,0,true,10,true);
    }
};

int main(){
    int low, high;
    cout << "enter low and high val: ";
    cin >> low >> high;

    Solution sol;
    cout<<"total integer: "<< sol.totalInteger(low, high)<<endl;

    return 0;
}