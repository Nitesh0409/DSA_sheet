#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMinReversals(string s)
    {
        // code here
        stack<char> st;
        int countOpen = 0;
        int countClosed = 0;

        if (s.size() % 2 != 0)
        {
            return -1;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '}')
            {
                if (st.empty())
                {
                    st.push(s[i]);
                    countClosed++;
                }
                else
                {
                    if (st.top() == '{')
                    {
                        st.pop();
                        countOpen--;
                    }
                    else
                    {
                        st.push(s[i]);
                        countClosed++;
                    }
                }
            }
            else
            {
                countOpen++;
                st.push(s[i]);
            }
        }
        if (st.size() % 2 == 0)
        {
            if (countOpen % 2 == 0 && countClosed % 2 == 0)
            {
                return (countOpen + countClosed) / 2;
            }
            else
            {
                return ((countOpen + countClosed) / 2) + 1;
            }
        }
        else
        {
            return -1;
        }
    }



    //there is another question where we have to add minimum no of bracket to make it valid ..
    //this also can be done by using same concept:

    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int countOpen = 0;
        int countClosed = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (st.empty())
                {
                    st.push(s[i]);
                    countClosed++;
                }
                else
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        countOpen--;
                    }
                    else
                    {
                        st.push(s[i]);
                        countClosed++;
                    }
                }
            }
            else
            {
                countOpen++;
                st.push(s[i]);
            }
        }

        return (countOpen + countClosed);
    }
};

int main()
{
    Solution sol;

    string input = "{{}}}}{{";

    cout<<sol.countMinReversals(input);

    return 0;
}