#include <bits/stdc++.h>

using i64 = long long;

template<typename T>
struct Fenwick {
    int n;
    std::vector<T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }

    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }

    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }

    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

void solve() {
    int n, m;
    std::cin >> n >> m;

    Fenwick<int> fen(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        fen.add(i, x);
    }

    for (int i = 0; i < m; i++) {
        int op, x, y;
        std::cin >> op >> x >> y;
        x--;

        if (op == 1) {
            fen.add(x, y);
        } else {
            int ans = fen.rangeSum(x, y);
            std::cout << ans << "\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}