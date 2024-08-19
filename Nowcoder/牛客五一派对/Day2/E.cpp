#include <bits/stdc++.h>

#define int long long

using namespace std;

const int P = 998244353;

void solve()
{
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d >> x >> y;

    map<int, int> mx, my, cntx, cnty;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            mx[i]++;
        }
    }
    if (x > 1) mx[x]++;

    for (int i = 2; i * i <= y; i++) {
        while (y % i == 0) {
            y /= i;
            my[i]++;
        }
    }
    if (y > 1) my[y]++;

    cntx = mx, cnty = my;
    for (auto &[x, y] : mx) y *= a;
    for (auto &[x, y] : my) y *= c;

    auto qpow = [&](int a, __int128 b) -> int {
        int res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            a = a * a % P;
            b >>= 1;
        }
        return res;
    };

    int ans = 1;
    for (auto [x, y] : mx) {
        if (my.find(x) == my.end()) continue;
        int a1 = y, b1 = my[x];
        int ad = cntx[x], bd = cnty[x];
        int bn = b1 + (d - c) * bd;
        int nb = d - c + 1;
        __int128 sum = 0;
        for (int i = a, ai = a1; i <= b; i++, ai += ad) {
            if (ai <= b1) sum += nb * ai;
            else if (ai >= bn) sum += nb * (b1 + bn) / 2;
            else {
                int len = (ai - b1) / bd;
                int bi = b1 + len * bd;
                sum += (len + 1) * (b1 + bi) / 2 + (nb - (len + 1)) * ai;
            }
        }
        ans = ans * qpow(x, sum) % P;
    }
    cout << ans << '\n';

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