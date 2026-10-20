#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, pos;
    cin >> n >> pos;
    if ( (n & (1 << pos)) != 0 )
        cout << "SET\n";
    else
        cout << "NOT SET\n";
    return 0;
}