#include<bits/stdc++.h>
using namespace std;

// basically to give pairs of relative prime from l to r , just provide consecutive integer value.

int main()
{
    int l = 1;
    int r = 8;

    cout << "YES \n";
    for (int i = l; i <= r; i = i + 2){
        cout << i << " " << i + 1 << "\n";
    }
        return 0;
}