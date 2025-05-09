#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        // approach:
        /*
        unsorted map to store : frequecy
        unsorted map to store bool of alreadyExist store if value already in stack or not

        for each char:
        - frequency decrease
        - if stack! empty and stack.top() > char and if char frequency is greater then 0, pop out
        - if already exist  skip
        - otherwise just add in stack

        and finaly store in result and return

        */

        stack<char> st;
        unordered_map<char, int> ump;
        unordered_map<char, bool> alreadyExist;

        for (char ch : s)
        {
            ump[ch]++;
        }

        for (char ch : s)
        {
            ump[ch]--;

            if (alreadyExist[ch])
            {
                continue;
            }
            while (!st.empty() && st.top() > ch && ump[st.top()] > 0)
            {

                alreadyExist[st.top()] = false;
                st.pop();
            }
            st.push(ch);
            alreadyExist[ch] = true;
        }

        string result = "";
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }

        return result;
    }
};

int main()
{
    string s = "abscsfb";
    Solution sol;
    cout << sol.removeDuplicateLetters(s) << endl;

    return 0;
}