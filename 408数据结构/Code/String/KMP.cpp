#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << log2(256) << endl;
    cout << ceil( log(51)/log(3)) << endl;
    cout << floor(log(50)/log(3) + 1) << endl;
    int count = 0;
    for (int i = 0; i < 7; i++)
    {
        count += pow(2, i);
        cout << i + 1 << ' ' << count << ' ' << pow(2, i) << endl;
    }
    return 0;
}