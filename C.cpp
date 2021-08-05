#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

auto max_self = [](int &a, int b) {
    a = max(a, b);
};

void argon17()
{
    int n;
    cin >> n;
    vector<int> dp(3);
    // dp[i] = min cost, i = last activity
    for (int day = 0; day < n; ++day) {
        vector<int> c(3), new_dp(3, -inf);
        cin >> c[0] >> c[1] >> c[2];
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i != j) {
                    max_self(new_dp[j], dp[i] + c[j]);
                }
            }
        }
        dp = new_dp;
    }
    cout << max({dp[0], dp[1], dp[2]}) << endl;
}
