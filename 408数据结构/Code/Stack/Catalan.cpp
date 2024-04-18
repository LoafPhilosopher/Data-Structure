#include <bits/stdc++.h>
#define int long long
#define endl "\n" 
int n;
int f[25];
using namespace std;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    f[0] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * (4 * i - 2) / (i + 1);
    // 这里用的是常见公式2
    cout << f[n] << endl;
    return 0;
}