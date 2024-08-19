// author : hhgzeng
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e1 + 5;
int f[N][N], a[N], b[N];

int C(int n, int m)
{
    if (f[n][m]) return f[n][m];
    if (m == 1) return n;
    if (m == 0 || n == m) return 1;
    if (m > n) return 0;
    f[n][m] = C(n - 1, m - 1) + C(n - 1, m);
    return f[n][m];
}

int Sum(int m)
{
    int ans = 1;
    for (int i = 0; i <= 9; i++) {
        if (b[i]) {
            ans *= C(m, b[i]);
            m -= b[i];
        }
    }
    return ans;
}

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        a[i + 1] = s[i] - '0';
        b[a[i + 1]]++;
    }

    int n = s.size();
    int ans = 0;
    for (int i = 1, j = n - 1; i <= n; i++, j--) {
        for (int k = 0; k < a[i]; k++) {
            if (b[k]) {
                b[k]--;
                ans += Sum(j);
                b[k]++;
            }
        }
        b[a[i]]--;
    }
    cout << ans << '\n';
    
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