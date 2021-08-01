#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

void argon17()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> dp(n, inf);
    dp[0] = 0;
    for (int i = 2; i < n; ++i){
        for (int ways = 1; ways <= 2; ++ways){
            if (i - ways < 0) continue;
            dp[i] = min(dp[i], dp[i - ways] + abs(a[i] - a[i - ways]));
        }
    }
    cout << dp[n - 1] << endl;
}
