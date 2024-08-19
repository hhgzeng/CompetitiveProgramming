// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H -> G
#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int a[N], vis[N];
bool b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }

    sort(a + 1, a + n + 1, greater<int>());

    for (int i = n; i <= a[1] + 1; i++) {
        bool flag = 1;
        for (int j = 1; a[j] >= i; j++) {
            int cnt = a[j] - i;
            while (cnt >= 0 && flag) {
                if (b[cnt] || vis[cnt] == i) flag = 0;
                else vis[cnt] = i;
                cnt -= i;
            }
            if (!flag) break;
        }
        if (flag) {
            cout << i << '\n';
            return;
        }
    }

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