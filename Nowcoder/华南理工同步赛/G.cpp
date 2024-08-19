#include <bits/stdc++.h>
using namespace std;
const int N = 30;
char a[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 25; j++) {
            a[i][j] = '.';
        }
    }

    bool flag = (n > m);
    if (flag) swap(n, m);

    if (n == 2) {
        a[1][2] = 'W', a[1][4] = 'W', a[1][6] = 'W';
        a[1][8] = 'W', a[1][10] = 'W', a[1][12] = 'W';
    } else if (n == 3) {
        a[2][2] = 'W', a[3][3] = 'W', a[2][4] = 'W';
        a[2][6] = 'W', a[3][7] = 'W', a[1][8] = 'W';
    } else if (n == 4) {
        a[3][1] = 'W', a[2][2] = 'W', a[3][3] = 'W';
        a[1][4] = 'W', a[3][5] = 'W', a[2][6] = 'W';
    } else if (n == 5) {
        a[3][1] = 'W', a[2][2] = 'W', a[3][3] = 'W';
        a[2][4] = 'W', a[5][2] = 'W', a[4][4] = 'W';
    }

    if (n == 3 && m == 4) a[1][4] = 'W', a[2][4] = '.';

    if (flag) {
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << a[j][i];
            }
            cout << "\n";
        }
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
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