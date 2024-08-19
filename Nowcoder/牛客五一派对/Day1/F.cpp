#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
struct node {
    int sum;
    int d;
} px[N], py[N];
int cntx[N], cnty[N], dx[5], dy[5];

void solve()
{
    int n, r;
    cin >> n >> r;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        cntx[x]++;
        cnty[y]++;
        mp[{x, y}]++;
    }

    int m = 1e5;
    for (int i = 0; i <= m; i++) {
        px[i].d = py[i].d = i;
        if (i + 2 * r <= m) {
            px[i].sum = cntx[i] + cntx[i + r] + cntx[i + 2 * r];
            py[i].sum = cnty[i] + cnty[i + r] + cnty[i + 2 * r];
        } else if (i + r <= m) {
            px[i].sum = cntx[i] + cntx[i + r];
            py[i].sum = cnty[i] + cnty[i + r];
        } else {
            px[i].sum = cntx[i];
            py[i].sum = cnty[i];
        }
    }

    sort(px, px + m + 1, [](auto a, auto b) { return a.sum > b.sum; });
    sort(py, py + m + 1, [](auto a, auto b) { return a.sum > b.sum; });

    int ans = 0;
    int My = py[0].sum;
    for (int i = 0; i <= m; i++) {
        int sumx = px[i].sum;
        if (ans >= sumx + My) break;
        dx[1] = px[i].d, dx[2] = dx[1] + r, dx[3] = dx[2] + r;

        for (int j = 0; j <= m; j++) {
            int sumy = py[j].sum;
            if (ans >= sumx + sumy) break;
            dy[1] = py[j].d, dy[2] = dy[1] + r, dy[3] = dy[2] + r;

            int total = 0;
            for (int k = 1; k <= 3; k++) {
                for (int l = 1; l <= 3; l++) {
                    if (mp.find({dx[k], dy[l]}) != mp.end()) {
                        total += mp[{dx[k], dy[l]}];
                    }
                }
            }
            if (ans < sumx + sumy - total) ans = sumx + sumy - total;
        }
    }
    cout << ans << '\n';
    
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