// author : hhgzeng
#include <bits/stdc++.h>

using namespace std;

const int N = 1e1 + 5;
int dp[N][N];

void init()
{
    for (int i = 0; i <= 9; i++) dp[1][i] = 1;
    for (int i = 2; i <= 10; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (abs(j - k) < 2) continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
}

int get(int x)
{
    if (x == 0) return 0;

    int res = 0;
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }

    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= 9; j++) {
            res += dp[i + 1][j];
        }
    }

    for (int i = 1; i < v[n - 1]; i++) {
        res += dp[n][i];
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= v[i] - 1; j++) {
            if (abs(j - v[i + 1]) < 2) continue;
            res += dp[i + 1][j];
        }
        if (i == 0 && abs(v[i] - v[i + 1]) >= 2) res++;  
        if (abs(v[i] - v[i + 1]) < 2) break;
    }

    return res;
}

void solve()
{
    init();
    int a, b;
    cin >> a >> b;
    cerr << get(b) << '\n';
    cerr << get(a - 1) << '\n';
    cout << get(b) - get(a - 1) << '\n';
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