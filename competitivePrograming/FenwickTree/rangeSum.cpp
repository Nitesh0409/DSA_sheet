#include <bits/stdc++.h>

using namespace std;


//----------------- Fenwick Tree Formation and query O(log n)----------------------------
class FenwickTree
{
private:
    int n;
    vector<int> bit;

public:
    FenwickTree(int size){
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val){
        while(idx <= n){
            bit[idx] += val;
            idx += idx & (-idx); //jump formward
        }
    }

    int query (int i){
        int sum = 0;
        while( i > 0){
            sum += bit[i];
            i -= (i & (-i));  //jump backward
        }

        return sum;
    }

    int sumInRange(int l, int r){
        return query(r) - query(l - 1);
    }

};

//------------------------------------------------------------------------------------

class Solution{
public:
    vector<int> SumInRange(vector<int> &nums, vector<pair<int, int>> &queries)
    {
        int n = nums.size();
        FenwickTree ft(n);

        //tree formation
        for (int i = 1; i <= n; i++){
            ft.update(i, nums[i-1]);
        }

        //find sum in range
        vector<int> result;
        for (auto &q : queries)
        {
            result.push_back(ft.sumInRange(q.first+1, q.second+1));  //making 0- index
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {2, 3, 4, 1, 5, 7, 8, 6};
    int n = nums.size();

    vector<pair<int, int>> queries = {{1, 4}, {4, 7}, {2, 6}, {0, 7}};

    Solution sol;
    vector<int> result = sol.SumInRange(nums, queries);

    for (int res: result)
        cout << res << " ";

        return 0;
}