#include<bits/stdc++.h>
using namespace std;

vector<string> generate(int n)
{
    // Your code here

    // approach:
    /*
    for traverse 1 to n
        and for each digit we will chech i/2 value
        if even we add 0 for ex : for 4 we will check 4/2 = 2 => 10 then add 0 , so 4 => 100
        similarly for odd add 1;
    */

    vector<string> result(n, "");
    result[0] = "1";
    for (int i = 1; i < n; i++)
    {
        int lastLink = (i - 1) / 2;
        if (i % 2 != 0)
        {
            result[i] = result[lastLink] + "0";
        }
        else
        {
            result[i] = result[lastLink] + "1";
        }
    }

    return result;
}


// another good apprach : by using queue...

vector<string> generate_by_queue(int n) {
vector<string> result;
queue<string> q;

q.push("1");  // Start with the binary representation of 1

while (n--) {
    string curr = q.front();
    q.pop();
    result.push_back(curr);

    // Generate the next binary numbers
    q.push(curr + "0");
    q.push(curr + "1");
}

return result;
}

int main(){

    int n = 5;
    vector<string> result = generate_by_queue(n);

    for(string str: result){
        cout << str << " ";
    }
    return 0;
}