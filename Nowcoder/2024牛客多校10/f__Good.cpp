#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::array<int, 2>> pts;
    
    auto valid = [&](int a, int b) {
        return 0 <= a && a < n && 0 <= b && b < n;
    };
    
    std::vector bad(n, std::vector<bool>(n));
    for (int i = 0; i < n * n; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        
        if (bad[x][y]) {
            std::cout << 0;
            continue;
        }
        
        std::cout << 1;
        for (auto [a, b] : pts) {
            int u = a - x;
            int v = b - y;
            int g = std::gcd(u, v);
            u /= g;
            v /= g;
            a = x;
            b = y;
            while (valid(a, b)) {
                bad[a][b] = true;
                a += u;
                b += v;
            }
            a = x;
            b = y;
            while (valid(a, b)) {
                bad[a][b] = true;
                a -= u;
                b -= v;
            }
        }
        pts.push_back({x, y});
    }
    
    std::cout << "\n";
    
    return 0;
}