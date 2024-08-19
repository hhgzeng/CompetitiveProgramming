#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
char s[N];

void solve()
{
    cin.getline(s + 1, N);
    
    int ans = 0;
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.' || s[i] == '?' || s[i] == '!') {
            if (ans) cout << ans % 10;
            ans = 0;
        } else {
            ans++;
        }
    }
    if (ans) cout << ans % 10;
    
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