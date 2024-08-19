#include <bits/stdc++.h>
#define int long long

using namespace std;

const int Max = 1e14;

const int N = 5e2 + 5;
string s1 = " COFFEE";
string s2 = " CHICKEN";
string s3 = " COFFEECHICKEN";
int f[N], len = 2;

void init()
{
    f[1] = 6;
    f[2] = 7;
    while (f[len++] <= Max) {
        f[len] = f[len - 1] + f[len - 2];
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;

    auto dfs = [&](auto && dfs, int x, int k, int length) -> void {
        if (x <= 3) {
            if (x == 1) {
                for (int i = k; i < min(k + length, (int)s1.size()); i++) cout << s1[i];
            } else if (x == 2) {
                for (int i = k; i < min(k + length, (int)s2.size()); i++) cout << s2[i];
            } else {
                for (int i = k; i < min(k + length, (int)s3.size()); i++) cout << s3[i];
            }
            return;
        }
        
        int len1 = f[x - 2];
        int len2 = f[x - 1];
        if (len1 >= k + length) dfs(dfs, x - 2, k, length);
        else if (k > len1) dfs(dfs, x - 1, k - len1, length);
        else {
            dfs(dfs, x - 2, k, len1 - k + 1);
            dfs(dfs, x - 1, 1, length - (len1 - k + 1));
        }
    };

    while (n > len) n -= 2;
    dfs(dfs, n, k, 10);
    cout << '\n';
    
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