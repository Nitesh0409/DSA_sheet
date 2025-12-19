#include<bits/stdc++.h>

using namespace std;
 
class Solution{
public:
    vector<int> segment;
    int n;

    //------------------------ segment formation O(n) ---------------------------------
    void segmentTreeFormation(vector<int>& nums){
        n = nums.size();

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

    //--------------------- node value  O(log n) --------------------------------------

    int getNodeValue(int l, int r){
        return query(0, 0, n - 1, l, r);
    }

    int query(int idx, int start, int end, int l, int r){
        //base case
        if(end < l || start > r)   //no overlap
            return 0; 

        if(l <= start && end <= r)  //complete overlap
            return segment[idx];

        //recursion
        int mid = start + (end - start) / 2;

        return query(2 * idx + 1, start, mid, l, r) + query(2 * idx + 2, mid + 1, end, l, r);
    }

    //----------------------- update query O(log n) -------------------------------------------
    void updateNode(int idx, int val){
        int mid = (n - 1 )/ 2;
        return updateQuery(idx, val, 0, 0, n-1);
    }

    void updateQuery(int idx, int val, int i, int l, int r){
        //base case
        if(l == r){
            segment[i] = val;
            return;
        }

        //recursion
        int mid = l + (r - l) / 2;
        if(idx <= mid){
            
            updateQuery(idx, val, 2 * i + 1, l, mid);
        }
        else{
            updateQuery(idx, val, 2 * i + 2, mid + 1, r);
        }

        segment[i] = segment[2 * i + 1] + segment[2 * i + 2];
    }
};

int main(){
    //segment tree formation

    vector<int> nums = {1, 2, 3, 4, 5};
    Solution sol;

    sol.segmentTreeFormation(nums);

    //---------------------------------------
    cout << "segment tree: ";
    for (int res : sol.segment)
    {
        cout << res << " , ";
    }
    cout << endl;

    //---------------------------------------
    cout << "queries : sum between l = 2 to r = 5 -> " ;
    cout << sol.getNodeValue(2, 5)<<endl;

    //---------------------------------------
    cout << "update idx = 2 with value = 1" << endl;
    sol.updateNode(2, 1);

    //---------------------------------------

    return 0;
}