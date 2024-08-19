#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int a[N], b[N];
string s[N];
vector<char> cnt;

void solve()
{
    int n = 5;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> a[i] >> b[i];
    }

    set<string> ans;
    for (char i = 'A'; i <= 'Z'; i++) {
        for (char j = 'A'; j <= 'Z'; j++) {
            for (char k = 'A'; k <= 'Z'; k++) {
                string t;
                t += i, t += j, t += k;
                bool flag = 1;
                for (int l = 1; l <= n; l++) {
                    int x = 0, y = 0;
                    for (int p = 0; p < 3; p++) {
                        if (count(t.begin(), t.end(), s[l][p]) > 0) x++;
                        if (s[l][p] == t[p]) y++;
                    }
                    if (a[l] != x || b[l] != y) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) ans.insert(t);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto t : ans) cout << t << "\n";
    
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