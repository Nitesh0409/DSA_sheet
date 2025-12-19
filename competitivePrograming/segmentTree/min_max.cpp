#include<bits/stdc++.h>

using namespace std;

class Solution{

public:
    vector<pair<int, int>> segment; // to store min and max;
    int n;

    //--------------------------- segment tree formation---------------------------------------

    void segmentFormation(vector<int>& nums){
        n = nums.size();

        segment.resize(4 * n);

        buildSegment(0, 0, n - 1, nums);
    }

    void buildSegment(int idx, int l, int r, vector<int>& nums){
        //base
        if(l == r){
            segment[idx] = {nums[l], nums[r]};
            return;
        }

        //recursive
        int mid = l + (r - l) / 2;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        buildSegment(left , l, mid, nums);
        buildSegment(right , mid + 1, r, nums);

        int minVal = min(segment[left].first, segment[right].first);
        int maxVal = max(segment[left].second, segment[right].second);

        segment[idx] = {minVal, maxVal};
    }


    //--------------------------- find min and max ---------------------------------------

    vector<pair<int,int>> findMinMax(vector<int>& nums, vector<vector<int>>& queries){
        //segment formation
        segmentFormation(nums);

        vector<pair<int, int>> result;
        
        for(vector<int>& q : queries){
            result.push_back(findNode(q[0], q[1]));
        }

        return result;
    }
    //------------------------------------------------------------------------------------

private:
    //------------------find node values for each query ---------------------------------------
    pair<int, int> findNode(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    pair<int,int> query(int idx, int start, int end, int l, int r){
        //if not overlap
        if(end < l || start > r){
            return {INT_MAX, INT_MIN};
        }

        //if complete overlap
        if(l <= start && end <= r){
            return segment[idx];
        }

        int mid = start + (end - start) / 2;

        auto [min1, max1] = query(2 * idx + 1, start, mid, l, r);
        auto [min2, max2] = query(2 * idx + 2, mid + 1, end, l, r);

        return {min(min1, min2), max(max1, max2)};
    }
};

int main(){

    vector<int> nums = {2, 4, 1, 3, 6};

    vector<vector<int>> queries = {{1, 4}, {0, 2}, {3, 4}};

    Solution sol;

    vector<pair<int, int>> p = sol.findMinMax(nums, queries);

    for(auto&[min, max] : p){
        cout << "min: " << min << " , "
             << "max: " << max << endl;
    }

    return 0;
}