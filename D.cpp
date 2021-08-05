#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

auto max_self = [](int &a, int b) {
    a = max(a, b);
};

void argon17()
{
    int n, W;
    cin >> n >> W;
    vector<int> dp(W + 1, 0);
    // dp[i] = max value, i = current weight
    for (int i = 0; i < n; ++i) {
        int wt, val;
        cin >> wt >> val;
        // rtl to avoid duplication, (0/1)
        for (int curWt = W - wt; curWt >= 0; --curWt) {
            max_self(dp[curWt + wt], dp[curWt] + val);
        }
    }
    int ans = 0;
    for (int &x : dp)
        max_self(ans, x);
    cout << ans << endl;
}
