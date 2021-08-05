#include <bits/stdc++.h>
using namespace std;

#define hell 1'000'000'007

bool inside(int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int dirs2[] = {0, 1, 0};

auto mod_self = [](int &n) {
    if (n >= hell) n -= hell;
};

const int mxN = 1e3 + 5;

char grid[mxN][mxN];

void argon17()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> dp(h, vector<int> (w, 0));
    // dp[i][j] = no of ways, (i, j) = cur pos
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            cin >> grid[r][c];
        }
    }
    dp[0][0] = 1;
    for (int r = 0; r < h; ++r) {
        for (int c = 0; c < w; ++c) {
            for (int i = 0; i < 2; ++i) {
                int nr = r + dirs2[i], nc = c + dirs2[i + 1];
                if (inside(nr, nc, h, w) && grid[nr][nc] == '.') {
                    dp[nr][nc] += dp[r][c];
                    mod_self(dp[nr][nc]);
                }
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}
