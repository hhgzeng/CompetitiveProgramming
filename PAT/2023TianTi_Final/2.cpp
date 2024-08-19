#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << a + b - 16 << "\n";
    cout << a + b - 3 << "\n";
    cout << a + b - 1 << "\n";
    cout << a + b << "\n";
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