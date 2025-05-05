#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

//-----------------------------------------------------------------------------------------
    //(Q - 1) => to print 1 to n number using recursion
    void printNum(int n){
        if(n == 1){
            cout << 1<<" ";
            return ;
        }

        printNum(n - 1);
        cout << n << " ";
    }

//-----------------------------------------------------------------------------------------

    //(Q -2) => to sort array by recursion
    // here using two time recursion like first time to sort and then to insert
    // although these working different but have same approach.

    void insert(vector<int>& arr, int temp){
        if(arr.size() == 0 || arr[arr.size() - 1] <= temp){  //base condition
            arr.push_back(temp);
            return;
        }

        int val = arr[arr.size() - 1];
        arr.pop_back();

        insert(arr, temp);

        arr.push_back(val);

        return;
    }

    void sort_array(vector<int>& arr){

        if(arr.size() == 1){
            return;
        }

        int temp = arr[arr.size() - 1];

        arr.pop_back();
        sort_array(arr);

        insert(arr, temp);

        return;
    }

//-----------------------------------------------------------------------------------------------

    // Q - 3 => sort stack , i will first try to solve by same earlier method;

    void insert_stack(stack<int>& s, int temp){
        if(s.empty()||s.top() >= temp){
            s.push(temp);
            return;
        }

        int val = s.top();
        s.pop();
        insert_stack(s, temp);

        s.push(val);
        return;
    }

    void sort_stack(stack<int> & s){
        if(s.size() == 1){
            return;
        }

        int temp = s.top();
        s.pop();
        sort_stack(s);

        insert_stack(s, temp);
        return;
    }
    //-----------------------------------------------------------------------------------------------
};

int main(){
    Solution sol;

// -----------------(Q - 1)------------

    // int n = 6;
    // sol.printNum(n);

//-------------------(Q - 2)-------------------

    // vector<int> arr = {4, 5, 7, 1, 3, 2};

    // cout << "original array :";
    // for (int i : arr)
    //     cout << i << " ";

    // sol.sort_array(arr);

    // cout << "\nsorted array :";
    // for(int i : arr)
    //     cout << i << " ";

    //-------------------(Q - 3)-----------------  
    vector<int> arr = {4, 5, 7, 1, 3, 2};
    stack<int> s;

    for(int val : arr){
        s.push(val);
    }

    sol.sort_stack(s);

    cout << "\nsorted stack: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    //-------------------(Q - 2)-------------------

    return 0;
};