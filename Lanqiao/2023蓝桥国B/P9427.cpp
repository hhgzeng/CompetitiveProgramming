#include <bits/stdc++.h> // 0%
using namespace std;
typedef __int128_t LL;
int n, m;
LL ans;

void print(LL x)
{
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void dfs(int x, int y)
{
    if (x == 0 && y == 0) {
        if (ans % 2023 == 0) {
            print(ans);
            exit(0);
        }
        return;
    }
    if (x) {
        ans = ans * 10 + 2;
        dfs(x - 1, y);
        ans = (ans - 2) / 10;
    }
    if (y) {
        ans = ans * 10 + 3;
        dfs(x, y - 1);
        ans = (ans - 3) / 10;
    }
}

void solve()  
{
    cin >> n >> m;
    dfs(n, m);
    cout << -1 << "\n";
    
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