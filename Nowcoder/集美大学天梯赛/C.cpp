#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double PI = 3.141592;

void solve()
{
    int r1, r2;
    cin >> r1 >> r2;
    cout << fixed << setprecision(6);
    cout << PI * (r2 * r2 - r1 * r1) << "\n";
    
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
}d