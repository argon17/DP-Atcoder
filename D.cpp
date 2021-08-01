#include <bits/stdc++.h>
using namespace std;

void argon17()
{
    int items, capacity;
    cin >> items >> capacity;
    vector<int> weights(items + 1), value(items + 1);
    for (int item = 1; item <= items; ++item) {
        cin >> weights[item] >> value[item];
    }
    vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));
    for (int item = 1; item <= items; ++item) {
        for (int weight = 1; weight <= capacity; ++weight) {
            dp[item][weight] = dp[item - 1][weight];
            if (weight >= weights[item])
                dp[item][weight] = max(dp[item][weight], value[item] + dp[item - 1][weight - weights[item]]);
        }
    }
    cout << dp[items][capacity] << endl;
}
