#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;
vector<int> b[N];
int a[N], f[N], q[N], lim[N];
int head, tail;

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[++n] = 0;

    int m;
    cin >> m;
    for (int i = 1; i <= n; i++) b[i].clear();
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        b[l].push_back(-r);
        b[r].push_back(l);
    }

    b[n].push_back(-n);
    b[n].push_back(n);

    int now = 0;
    for (int i = 1, j = 1; i <= n; i++) { // l : j, r : i
        for (auto x : b[i]) {
            if (x > 0 && x >= j) {
                now++;
            }
        }
        while (now > 0 && j <= i) {
            for (auto x : b[j]) {
                if (x < 0 && -x <= i) {
                    now--;
                }
            }
            j++;
        }
        lim[i] = j;
    }

    f[0] = 0, f[1] = a[1];
    head = tail = 1;
    q[tail++] = 0, q[tail++] = 1;

    for (int i = 2; i <= n; i++) {
        int pos = lim[i - 1] - 1;
        while (q[head] < pos) head++;
        f[i] = f[q[head]] + a[i];
        while (head < tail && f[q[tail - 1]] >= f[i]) tail--;
        q[tail++] = i;
    }

    cout << f[n] << '\n';

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