// author : hhgzeng
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

void solve()
{
    int n;
    cin >> n;
    auto f = [](auto && f, int n) {    // lambda 递归写法
        if (n == 1) return 1;
        return f(f, n - 1) + n;
    };
    cout << f(f, n) << '\n';

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