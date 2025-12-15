#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> segment;
    int n;

    void segmentTreeFormation(vector<int> &nums)
    {
        n = nums.size();

        segment.resize(n * 4);

        buildSegment(0, 0, n - 1, nums);
    }

    void buildSegment(int idx, int l, int r, vector<int> &nums)
    {
        // base case
        if (l == r)
        {
            segment[idx] = nums[l];
            return;
        }

        // recursive
        int mid = l + (r - l) / 2;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        buildSegment(left, l, mid, nums);
        buildSegment(right, mid + 1, r, nums);

        segment[idx] = segment[left] + segment[right];
    }

    // for getting value for queries
    int getNodeValue(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    int query(int idx, int start, int end, int l, int r)
    {

        if (end < l || start > r) // no overlap
            return 0;

        if (l <= start && end <= r) // complete overlap
            return segment[idx];

        int mid = start + (end - start) / 2;

        return query(2 * idx + 1, start, mid, l, r) + query(2 * idx + 2, mid + 1, end, l, r);
    }

public:
    vector<int> getSum(vector<int> &nums, vector<vector<int>> &queries)
    {   
        //segment tree formation
        segmentTreeFormation(nums);

        //return result
        vector<int> result;

        for (vector<int> &q : queries)
        {
            result.push_back(getNodeValue(q[0], q[1]));
        }

        return result;
    }
};

int main()
{
    // task to get sum of l to r
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    vector<vector<int>> queries; // queries[i] = [l,r];

    queries = {{1, 2}, {0, 3}, {2, 5}};

    Solution sol;
    vector<int> result = sol.getSum(nums, queries);

    for (int res : result)
    {
        cout << res << " ";
    }

    return 0;
}