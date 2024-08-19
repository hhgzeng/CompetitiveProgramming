#include <bits/stdc++.h>

using i64 = long long;

constexpr int pw[] = {1, 10, 100, 1000, 10000, 100000};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> dis(pw[n], -1);
    dis[0] = 0;
    std::queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto t : {1, 9}) {
            for (int l = 0; l < n; l++) {
                int y = x;
                for (int r = l; r < n; r++) {
                    int d = y / pw[r] % 10;
                    y += pw[r] * ((d + t) % 10 - d);
                    if (dis[y] == -1) {
                        dis[y] = dis[x] + 1;
                        q.push(y);
                    }
                }
            }
        }
    }

    std::vector<int> ok(pw[n], 1);
    while (m--) {
        std::string s;
        int t;
        std::cin >> s >> t;

        for (int y = 0; y < pw[n]; y++) {
            int w = 0;
            for (int i = 0; i < n; i++) {
                w += (s[i] - '0' + y / pw[i] % 10) % 10 * pw[i];
            }
            if (dis[y] > t) {
                ok[w] = 0;
            }
            if (y == 0 && t == 1) {
                ok[w] = 0;
            }
            if (n == 1 && (y + t) % 2 != 0) {
                ok[w] = 0;
            }
        }
    }

    int cnt = std::count(ok.begin(), ok.end(), 1);
    if (cnt == 0) {
        std::cout << "IMPOSSIBLE\n";
    } else if (cnt > 1) {
        std::cout << "MANY\n";
    } else {
        int x = std::find(ok.begin(), ok.end(), 1) - ok.begin();
        for (int i = 0; i < n; i++) {
            std::cout << x / pw[i] % 10;
        }
        std::cout << "\n";
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