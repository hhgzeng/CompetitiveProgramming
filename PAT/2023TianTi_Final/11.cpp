#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
vector<int> a[20];
int ans[N];

void merge(int l, int r, int n)
{
    if (r - l == 1) {
        ans[l] = a[n][r / (1 << n)];
    } else {
        int mid = (l + r) / 2;
        merge(l, mid, n - 1);
        merge(mid + 1, r, n - 1);
        int t = a[n][r / (1 << n)];
        bool flag = 1;
        for (int i = l; i <= r; i++) {
            if (i % 2 == 0 && !ans[i] && t >= ans[i - 1]) {
                ans[i] = t;
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "No Solution";
            exit(0);
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        a[i].push_back(0);
        for (int j = 1; j <= 1 << (n - i); j++) {
            int t; cin >> t;
            a[i].push_back(t);
        }
    }
    
    merge(1, 1 << n, n);
    
    int w;
    cin >> w;

    for (int i = 1; i <= 1 << n; i++) {
        if (ans[i]) cout << ans[i] << " ";
        else cout << w << " ";
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