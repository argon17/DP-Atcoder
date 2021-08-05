#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

/*------------------------------------------------*/

auto min_self = [](int &a, int b) {
    a = min(a, b);
};

void argon17()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int &x : h) cin >> x;
    vector<int> dp(n, inf);
    // dp[i] = min cost, i = curHeight
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= i + k; ++j) {
            if (j < n)
                min_self(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1] << endl;
}
