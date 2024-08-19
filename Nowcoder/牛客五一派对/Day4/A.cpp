// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H
#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
bool vis[N][N];

void init()
{
    vis[0][0] = 0;
    for (int i = 0; i <= N - 5; i++) {
        for (int j = 0; j <= N - 5; j++) {
            if (vis[i][j]) continue;
            for (int k = 1; i + k <= N - 5; k++) {
                for (int s = 0; j + s * k <= N - 5; s++) {
                    vis[i + k][j + s * k] = 1;
                }
            }
            for (int k = 1; j + k <= N - 5; k++) {
                for (int s = 0; i + s * k <= N - 5; s++) {
                    vis[i + s * k][j + k] = 1;
                }
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    if (!vis[n][m]) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    init();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}