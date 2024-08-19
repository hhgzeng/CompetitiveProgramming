#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> f;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        f[a[i]]++;
    }
    std::sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int r = std::upper_bound(a.begin(), a.end(), i) - a.begin();
        if (n - r + f[i] < i) {
            break;
        }
        if (n - r < i) {
            r -= i - (n - r);
        }
        int lo = -n, hi = 0;
        while (lo < hi) {
            int x = (lo + hi - 1) / 2;
            int s = std::lower_bound(a.begin(), a.end(), x) - a.begin();
            if (i - x <= s + f[x]) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }
        int l = std::lower_bound(a.begin(), a.end(), lo) - a.begin();
        l += (i - lo) - l;
        ans = std::max(ans, r - l);
    }
    f.clear();
    std::reverse(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] = -a[i];
        f[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        int r = std::upper_bound(a.begin(), a.end(), i) - a.begin();
        if (n - r + f[i] < i) {
            break;
        }
        if (n - r < i) {
            r -= i - (n - r);
        }
        int lo = -n, hi = 0;
        while (lo < hi) {
            int x = (lo + hi - 1) / 2;
            int s = std::lower_bound(a.begin(), a.end(), x) - a.begin();
            if (i - x <= s + f[x]) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }
        int l = std::lower_bound(a.begin(), a.end(), lo) - a.begin();
        l += (i - lo) - l;
        ans = std::max(ans, r - l);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    std::cin >> T;

    while (T--) {
    	solve();
    }

    return 0;
}