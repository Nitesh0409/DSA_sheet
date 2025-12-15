#include<bits/stdc++.h>

using namespace std;
 
class Solution{
public:
    vector<int> segment;
    int n;

    void segmentTreeFormation(vector<int>& nums){
        n = nums.size();

        // int s = (n % 2 == 0) ? 2 * n : 2 * n - 1; //not work here will confirm later

        segment.resize(n * 4);

        buildSegment(0, 0, n - 1, nums);
    }

    void buildSegment(int idx , int l, int r, vector<int> &nums)
    {
        //base case
        if(l == r){
            segment[idx] = nums[l];
            return;
        }

        //recursive
        int mid = l + (r - l) / 2;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        buildSegment(left, l, mid, nums);
        buildSegment(right , mid + 1, r, nums);

        segment[idx] = segment[left] + segment[right];
    }

    
    //for getting value for queries
    int getNodeValue(int l, int r){
        return query(0, 0, n - 1, l, r);
    }

    int query(int idx, int start, int end, int l, int r){
        
        if(end < l || start > r)   //no overlap
            return 0; 

        if(l <= start && end <= r)  //complete overlap
            return segment[idx];

        int mid = start + (end - start) / 2;

        return query(2 * idx + 1, start, mid, l, r) + query(2 * idx + 2, mid + 1, end, l, r);
    }

};

int main(){
    //segment tree formation

    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sol;

    sol.segmentTreeFormation(nums);
    
    for(int res : sol.segment){
        cout << res << " , ";
    }

    return 0;
}