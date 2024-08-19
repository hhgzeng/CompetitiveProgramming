#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int P = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    if (n + 1e9 >= P) {
        cout << P - n << "\n";
    } else {
        cout << 107 << "\n";
    }
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