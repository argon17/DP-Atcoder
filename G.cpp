#include <bits/stdc++.h>
using namespace std;

auto min_self = [](int &a, int b) {
    a = min(a, b);
};

auto max_self = [](int &a, int b) {
    a = max(a, b);
};

/*-------------------------------------------------------------------------------------------------------------
what? how? why? edge cases?
-------------------------------------------------------------------------------------------------------------*/

const int mxN = 1e5 + 5;

vector<int> edges[mxN];

int inDegree[mxN];
int dist[mxN];
bool vis[mxN];

void dfs(int u) {
    assert(!vis[u]);
    vis[u] = 1;
    for (int v : edges[u]) {
        max_self(dist[v], dist[u] + 1);
        --inDegree[v];
        if (inDegree[v] == 0) dfs(v);
    }
}

void argon17()
{
    int n, e;
    cin >> n >> e;
    while (e--) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        inDegree[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i] && inDegree[i] == 0) dfs(i);
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        max_self(ans, dist[i]);
    }
    cout << ans << endl;
}
