#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:

// another solution is possible by dp.. will do later

//this is stack solution.... new concept..
    int validParanthesis(string &s)
    {

        int n = s.size();
        stack<int> st;
        st.push(-1);

        int longest = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    longest = max(longest, i - st.top());
                }
                else
                {
                    st.push(i);
                }
            }
        }
        return longest;
    }


    //more optimization : use two way traversal => basic idea as only '(' and ')' so just count total occurence from both side
    // and based on more number of closing or opening bracket .

    // C++ program to find length of the
    // longest valid substring

    int maxLength(string s)
    {
        int maxLen = 0;

        // Left to Right Traversal
        int open = 0, close = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                open++;
            }
            else if (ch == ')')
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * close);
            }
            else if (close > open)
            {
                open = close = 0;
            }
        }

        // Right to Left Traversal
        open = close = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                open++;
            }
            else if (s[i] == ')')
            {
                close++;
            }

            if (open == close)
            {
                maxLen = max(maxLen, 2 * open);
            }
            else if (open > close)
            {
                open = close = 0;
            }
        }

        return maxLen;
    }

};

int main(){
    string s = "{({[]})}";

    Solution sol;
    cout<<sol.validParanthesis(s)<<endl;

    return 0;
}