#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[N];
int c[N], p[N];
int dp[N][2];
int ans;

void dfs(int x)
{
    if (c[x] == 1) dp[x][1]++;
    else dp[x][0]++;
    for (auto y : g[x]) {
        dfs(y);
        dp[x][1] += dp[y][1];
        dp[x][0] += dp[y][0];
    }
}

void DFS(int x)
{
    for (auto y : g[x]) {
        dfs(y);
        if (abs(dp[y][1] - dp[y][0]) > 1) {
            
        }
    }
}

void solve()
{   
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> c[i] >> p[i] >> k;
        for (int j = 1; j <= k; j++) {
            int v; cin >> v;
            g[i].push_back(v);
        }
    }

    dfs(1);
    DFS(1);
    
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}