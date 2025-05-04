// this is genral algorithm , for more details : https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> generalMajorityElement(vector<int> &arr, int k)
    {
        int n = arr.size();

        if(k < 3){
            return {};
        }

        unordered_map<int, int> candidates;

        // Step 1: Find potential candidates (at most k - 1)
        for (int num : arr)
        {
            // If already a candidate, increase count
            if (candidates.count(num))
            {
                candidates[num]++;
            }
            // If we have less than k-1 candidates, add new one
            else if (candidates.size() < k - 1)
            {
                candidates[num] = 1;
            }
            // Otherwise, decrease count of all current candidates
            else
            {
                for (auto it = candidates.begin(); it != candidates.end();)
                {
                    it->second--;
                    if (it->second == 0)
                        it = candidates.erase(it);
                    else
                        ++it;
                }
            }
        }

        // Step 2: Count actual occurrences of candidates
        unordered_map<int, int> actualCount;
        for (int num : arr)
        {
            if (candidates.count(num))
            {
                actualCount[num]++;
            }
        }

        // Step 3: Add elements with count > n/k to result
        vector<int> result;
        for (auto &pair : actualCount)
        {
            if (pair.second > n / k)
            {
                result.push_back(pair.first);
            }
        }

        return result;
    }
};


int main(){
    vector<int> arr = {1, 2, 1, 1, 2, 5, 3, 2};
    int k = 3;

    Solution sol;

    vector<int> elements = sol.generalMajorityElement(arr, k);

    for(int i : elements){
        cout << i << " " << endl;
    }

    return 0;
}