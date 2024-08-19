#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 5;
vector<int> g[N];
int match[N], vis[N];

bool dfs(int x, int p)
{
    if (vis[x] == p) return false;
    vis[x] = p;
    for (auto y : g[x]) {
        if (!match[y] || dfs(match[y], p)) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) match[i] = 0;
    for (int i = 1; i <= n; i++) vis[i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int a; cin >> a;
            if (a == 1) g[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dfs(i, i)) ans++;
    }

    if (ans == n) cout << "Yes\n";
    else cout << "No\n";

}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}