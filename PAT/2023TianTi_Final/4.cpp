#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c == a * b) cout << "Lv Yan\n";
    else if (c == a + b) cout << "Tu Dou\n";
    else cout << "zhe du shi sha ya!\n";
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}