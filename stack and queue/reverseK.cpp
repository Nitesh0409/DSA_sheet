#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    queue<int> reverseFirstK(queue<int> q, int k)
    {
        // code here

        k = k % q.size();
        
        stack<int> st;
        queue<int> result;

        while(!q.empty() && k > 0)
        {                                   // stack formation till k and queue removal till k
            st.push(q.front());
            q.pop();
            k--;
        }

        while(!st.empty()){                 // extract stack and put it in result;
            result.push(st.top());
            st.pop();
        }

        while(!q.empty()){                  //now put all remaining queue value in result
            result.push(q.front());
            q.pop();
        }

        return result;
    }
};

int main(){
    queue<int> q;

    vector<int> arr = {1,2,3,4,5};

    for(int i : arr){
        q.push(i);
    }

    int k = 3;

    Solution sol;
    queue<int> result = sol.reverseFirstK(q, k);

    while(!result.empty()){
        cout << result.front() << " ";
        result.pop();
    }

    return 0;
}