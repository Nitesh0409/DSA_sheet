#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool duplicateBracket(string s)
    {

        // check for every character
        // if '(' then push and if  ')' the pop till we find '(' if first poping element is '(' then return true;
        stack<char> st;
        for (char ch : s)
        {
            if (st.empty() && ch == ')')
            {
                return true;
            }
            else if (!st.empty() && ch == ')')
            {
                if (st.top() == '(')
                {
                    return true;
                }
                while (!st.empty() && st.top() != '(')
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }

        return false;
    }
};

int main()
{

    string s = "((a+(b)) +(c) + (d))";
    Solution sol;

    cout << sol.duplicateBracket(s) << endl;

    return 0;
}