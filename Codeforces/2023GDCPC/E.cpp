#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int p[N][26], exist[N];
int len;

void add(int x)
{
    exist[x] = 0;
    memset(p[x], 0, sizeof(p[x]));
}

void insert(string s)
{
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (!p[pos][c]) {
            p[pos][c] = ++len;
            add(len);
        }
        pos = p[pos][c];
        exist[pos]++;
    }
}

void solve()
{
    add(0);
    len = 0;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
    }

    k = n - k;
    int pos = 0;
    string ans;
    
    while (true) {
        int cnt = pos;
        for (int i = 25; i >= 0; i--) {
            if (exist[p[pos][i]] > 1 && k >= exist[p[pos][i]] - 1) {
                k -= exist[p[pos][i]] - 1;
            } else if (k < exist[p[pos][i]] - 1) {
                pos = p[pos][i];
                ans.push_back(i + 'a');
                break;
            } else if (k == 0 && exist[p[pos][i]] > 1) {
                pos = p[pos][i];
                ans.push_back(i + 'a');
                break;
            }
        }
        if (cnt == pos) break;
    }

    if (!pos) cout << "EMPTY\n";
    else cout << ans << '\n';

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