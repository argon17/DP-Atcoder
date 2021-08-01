#include <bits/stdc++.h>
using namespace std;

void argon17()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(3));
    for (auto &x : a)
        cin >> x[0] >> x[1] >> x[2];
    vector<vector<int>> dp(n, vector<int>(3, 0));
    for (int activity = 0; activity < 3; ++activity) {
        dp[0][activity] = a[0][activity];
    }
    for (int day = 1; day < n; ++day) {
        for (int activity = 0; activity < 3; ++activity) {
            for (int prevActivity = 0; prevActivity < 3; ++prevActivity) {
                if (activity == prevActivity) continue;
                dp[day][activity] = max(dp[day][activity], a[day][activity] + dp[day - 1][prevActivity]);
            }
        }
    }
    cout << *max_element(dp[n - 1].begin(), dp[n-1].end()) << endl;
}