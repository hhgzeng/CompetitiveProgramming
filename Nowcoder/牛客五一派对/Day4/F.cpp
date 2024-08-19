// author: hhgzeng  | easy to hard: B -> D -> F -> A -> H
#include <bits/stdc++.h>

#define int long long

using namespace std;

int dp[110];

void init()
{
    for (int i = 1; i <= 9; i++) dp[i] = dp[i - 1] + (i % 3 == 0);
    for (int i = 10; i <= 99; i++) {
        dp[i] = dp[i - 1];
        int p1 = i % 10, p2 = i / 10, p3 = i;
        if (p1 % 3 == 0 || p2 % 3 == 0 || p3 % 3 == 0) dp[i]++;
    }
}

int find(int x)
{
    if (x < 100) return dp[x];
    else return dp[99] + x - 99;
}

void solve()
{
    int l, r;
    cin >> l >> r;
    cout << find(r) - find(l - 1) << '\n';
}

signed main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    init();
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}