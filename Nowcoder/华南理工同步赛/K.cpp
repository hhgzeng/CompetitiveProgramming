#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int val[N], f[N], p[N];
int len;

int find(int& x)
{
    return f[x] == x ? x : f[x] = find(f[x]);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    len = n;
    for (int i = 0; i <= n; i++) val[i] = 0;
    for (int i = 0; i <= n; i++) f[i] = n + 1;
    for (int i = 0; i <= q; i++) p[i] = 0;

    for (int i = 0; i <= q; i++) {
        p[i] = ++len;
        f[len] = len;
        val[len] = i;
    }

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op & 1) {
            int k = val[find(x)];
            f[x] = p[k + 1];
        } else {
            f[p[x]] = p[x + 1];
            p[x] = ++len;
            f[len] = len;
            val[len] = x;
        }
    }

    for (int i = 1; i <= n; i++) cout << val[find(i)] << " ";
    cout << "\n";

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