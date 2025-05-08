#include<bits/stdc++.h>

using namespace std;

//need to solve this again.... as i did not understand concept completey..................

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string result;

        for (char ch : num)
        {
            while (!result.empty() && k > 0 && ch < result.back())
            {
                result.pop_back();
                k--;
            }
            result.push_back(ch);
        }

        // Remove remaining digits from the end if k > 0
        while (k > 0 && !result.empty())
        {
            result.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < result.size() && result[start] == '0')
        {
            start++;
        }

        result = result.substr(start);

        return result.empty() ? "0" : result;
    }
};

int main()
{
    string num = "33526221184202197273";
    int k = 19;

    Solution sol;
    string smallest = sol.removeKdigits(num, k);

    cout << "Smallest number after removing " << k << " digits: " << smallest << endl;

    return 0;
}
