// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H
#include <bits/stdc++.h>

using namespace std;

const double PI = 3.1415926;

void solve()
{
    double r, a, b, h;
    cin >> r >> a >> b >> h;
    if (2 * r < b) cout << "Drop\n";
    else {
        double e = PI / 2 - atan((a - b) / (2 * h));
        double len = 2 * r * sin(e);
        double ans = (len - b) / (a - b) * h + r * cos(e);
        cout << "Stuck\n";
        cout << fixed << setprecision(8) << ans << '\n';
    }
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