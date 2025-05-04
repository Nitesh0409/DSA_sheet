// question link: https://leetcode.com/problems/majority-element-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    // brute force solution will be same as majority element -1 , basicallywhere just count frequency of each element and if that will be more that n/3 then that will be solution but it will give T=> O(n^2) and s => O(1);

    // to make more optimal we can use hashmap where store frequency of digit but , t => O(n), and s = O(n);


    //best approach:
    // this is moore's algorithm with some modification, t => O(n), s => O(1)
    vector<int> majorityElement_ii_opt(vector<int> arr){
        vector<int> result;
        int n = arr.size();

        int count_1 = 0, count_2 = 0;
        int element_1 = -1, element_2 = -1;

        for (int i = 0; i < n;i++){
            if(element_1 == arr[i]){
                count_1++;
            }
            else if(element_2 == arr[i]){
                count_2++;
            }
            else if(count_1 == 0){
                element_1 = arr[i];
                count_1++;
            }
            else if(count_2 == 0){
                element_2 = arr[i];
                count_2++;
            }
        }

        count_1 = 0;
        count_2 = 0;

        for(int element : arr){
            if (element == element_1){
                count_1++;
            }else if(element == element_2){
                count_2++;
            }
        }

        if(count_1 > (n/3))
            result.push_back(element_1);
        if(count_2 > (n/3))
            result.push_back(element_2);

        return result;
    }
};

int main(){

    vector<int> arr = {1, 2, 1, 1, 2, 5, 3, 2};

    Solution sol;
    vector<int> elements = sol.majorityElement_ii_opt(arr);

    for(int i: elements){
        cout << i << " "<< endl;
    }

    return 0;
}