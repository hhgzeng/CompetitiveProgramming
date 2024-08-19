#include <bits/stdc++.h>

using i64 = long long;

int query(int a, int b) {
    std::cout << "? " << a << " " << b << std::endl;
    int res;
    std::cin >> res;
    return res;
}

void solve() {
    int l = 2, r = 999;
    while (l < r) {
        int a = (r - l) / 3 + l;
        int b = (r - l) * 2 / 3 + l;
        int res = query(a, b);
        if (res == a * b) {
            l = b + 1;
        } else if (res == a * (b + 1)) {
            l = a + 1;
            r = b;
        } else {
            r = a;
        }
    }
    std::cout << "! " << l << std::endl;
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