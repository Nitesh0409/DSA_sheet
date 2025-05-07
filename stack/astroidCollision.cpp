#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* although this question is based on same concept of next greater/smaller element still not able to write correct code  in one time.
        i have to practice more on handeling edge cases.. and will implement all code again..
    */

    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        if (n <= 1)  //edge case handling
        { 
            return asteroids;
        }
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            bool destroyed = false;  //determine whether asteroid will remain till end or not.

            while (!s.empty() && s.top() > 0 && asteroids[i] < 0) // just one case because position in space relative so s.top is negative then it will not able to collapse with next asteroid.. 
            {
                if (abs(asteroids[i]) > abs(s.top()))  //collision code
                {
                    s.pop();
                }
                else if (abs(asteroids[i]) == abs(s.top()))
                {
                    s.pop();
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed)  //adding non destroyed asteroid
            {
                s.push(asteroids[i]);
            }
        }

        int rSize = s.size();
        vector<int> result(rSize);
        for (int i = rSize - 1; i >= 0; --i)
        {
            result[i] = s.top();
            s.pop();
        }

        return result;
    }
};


int main(){

    vector<int> arr = {10, 2, -5};
    Solution sol;

    vector<int> result = sol.asteroidCollision(arr);

    for(int i: result){
        cout << i << " ";
    }

    return 0;
}