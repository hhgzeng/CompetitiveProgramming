#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N];

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    
    while (q--) {
        int x, k;
        cin >> x >> k;
        int p = lower_bound(a + 1, a + n + 1, x) - a;
        if (p == 1) {
            cout << a[k] - x << "\n";
        } else if (p == n + 1) {
            cout << x - a[n - k + 1] << "\n";
        } else if (k == n) {
            cout << max(x - a[1], a[n] - x) << "\n";
        } else {
            int l = 1, r = min(k, p - 1);
            while (l < r) {
                int mid = (l + r) / 2;
                int t = k - mid - 1;
                if (x - a[p - mid] >= a[min(p + t, n)] - x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (p + k - l > n) {
                cout << x - a[p - (k - (n - p + 1))] << "\n";
            } else if (x - a[p - l] < a[p + k - l - 1] - x) {
                cout << a[p + k - l - 1] - x << "\n";
            } else {
                cout << min(x - a[p - l], a[p + k - l] - x) << "\n";
            }
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