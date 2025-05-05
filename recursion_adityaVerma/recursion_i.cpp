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

    // (q-4) deleting middle element in the stack

    void deleteMiddle(stack<int>& s, int& mid){

        if(mid == 0){
            s.pop();
            return;
        }

        int temp = s.top();
        s.pop();
        mid -= 1;
        deleteMiddle(s,mid);

        s.push(temp);

        return;
    }

    //-----------------------------------------------------------------------------------------------
    //(Q - 5) => reverse stack by recursion (similar as sorting);
    void insertStack(stack<int>& s, int temp){
        if(s.empty()){
            s.push(temp);
            return;
        }

        int val = s.top();
        s.pop();
        insertStack(s, temp);

        s.push(val);
    }

    void reverseStack(stack<int>&s){
        if(s.empty()){
            return;
        }

        int temp = s.top();
        s.pop();
        reverseStack(s);

        insertStack(s, temp);
    }

    //-----------------------------------------------------------------------------------------------
/*
    0
    01
    0110
    01101001
    0110100110010110

    we have something this type of dictionary where user give input n(row), k(col) then we have to return value at that place
    for example n=4,k=5 then val = 1

    we have to solve this by recursion
*/

    int kthChar(int n, int k){
        if( n == 1 && k == 1 ){
            return 0;
        }

        int mid = pow(2, n-1)/2;
        
        if(k <= mid){
            return kthChar(n - 1, k);
        }
        else{
            return !(kthChar(n - 1, k-mid));
        }
    }
    //-----------------------------------------------------------------------------------------------

    // Q-7 Tower of Hanoi (best problem)

    void towerHanoi(int n, int s, int h, int d){
        if(n == 1){
            cout << "move disk " << n <<" from " << s << " to " << d << endl;
            return;
        }

        towerHanoi(n - 1, s, d, h);
        cout << "move disk " << n << " from " << s << " to " << d << endl;
        
        towerHanoi(n - 1, h, s, d);
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
    // vector<int> arr = {4, 5, 7, 1, 3, 2};
    // stack<int> s;

    // for(int val : arr){
    //     s.push(val);
    // }

    // sol.sort_stack(s);

    // cout << "\nsorted stack: ";
    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    //-------------------(Q - 4)-------------------

    // vector<int> arr = {4, 5, 7, 1, 3};
    // stack<int> s;

    
    // for (int val : arr)
    // {
    //     s.push(val);
    // }
    // int mid = (s.size() / 2);

    // sol.deleteMiddle(s, mid);

    // while(!s.empty()){
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    //-------------------(Q - 5)-------------------

    // vector<int> arr = {4, 5, 7, 1, 3};
    // stack<int> s;

    // for (int val : arr)
    // {
    //     s.push(val);
    // }

    // sol.reverseStack(s);

    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    //-------------------(Q - 6)-------------------

    // int n = 4, k = 5;
    // cout << sol.kthChar(n, k);

    //-------------------(Q - 7)-------------------

    int n = 3;
    int s =1, d =3, h = 2;
    sol.towerHanoi(n, s, h, d);

    return 0;
};