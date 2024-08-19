#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int pre[N], nxt[N], ans[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n + 1; i++) pre[i] = i - 1;
    for (int i = 0; i <= n; i++) nxt[i] = i + 1;

    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1) {
            cin >> x;
        } else {
            x = pre[n + 1];
        }

        pre[nxt[x]] = pre[x];
        nxt[pre[x]] = nxt[x];

        pre[nxt[0]] = x;
        pre[x] = 0;
        nxt[x] = nxt[0];
        nxt[0] = x;

    }

    for (int i = nxt[0], j = 1; i != n + 1; i = nxt[i], j++) ans[i] = j;
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
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