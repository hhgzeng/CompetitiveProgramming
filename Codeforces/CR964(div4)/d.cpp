#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int x = 0;
    for (auto &c : s) {
        if (x < t.size() && c == t[x]) {
            x++;
            continue;
        }
        if (c == '?') {
            c = x >= t.size() ? 'a' : t[x];
            x++;
        }
    }
    if (x < t.size()) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        std::cout << s << "\n";
    }
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