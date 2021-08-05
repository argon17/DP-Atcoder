#include <bits/stdc++.h>
using namespace std;

#define inf 1e18

auto max_self = [](int &a, int b) {
    a = max(a, b);
};

auto min_self = [](int &a, int b) {
    a = min(a, b);
};

void argon17()
{
    int n, W;
    cin >> n >> W;
    int mxVal = n * 1000;
    vector<int> dp(mxVal + 1, inf);
    dp[0] = 0;
    // dp[i] = min weight, i = cur val
    for (int item = 0; item < n; ++item) {
        int wt, val;
        cin >> wt >> val;
        // rtl to avoid duplication, (0/1)
        for (int curVal = mxVal - val; curVal >= 0; --curVal) {
            min_self(dp[curVal + val], dp[curVal] + wt);
        }
    }
    int ans = 0;
    for (int i = mxVal; i >= 0; --i) {
        if (dp[i] <= W) {
            cout << i << endl;
            return;
        }
    }
}

