#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    int a, b;
    cin >> a >> b;
    int aa = 0, bb = 0;
    int t1 = a, t2 = b;
    while (t1) {
        aa += t1 % 10;
        t1 /= 10;
    }
    while (t2) {
        bb += t2 % 10;
        t2 /= 10;
    }
    if (a % bb == 0 && b % aa == 0 || a % bb != 0 && b % aa != 0) {
        if (a > b) cout << "A\n";
        else cout << "B\n";
    } else if (a % bb == 0) {
        cout << "A\n";
    } else {
        cout << "B\n";
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