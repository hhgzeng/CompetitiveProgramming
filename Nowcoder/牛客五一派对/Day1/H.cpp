#include <bits/stdc++.h>

using namespace std;

const int N = 1e1 + 5;
vector<int> g[N];
int du[N];

void solve()
{
    for (int i = 1; i <= 6; i++) g[i].clear(), du[i] = 0;
    
    for (int i = 1; i <= 5; i++) {
        int a, b;
        cin >> a >> b;
        du[a]++, du[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    sort(du + 1, du + 6 + 1, greater<int>());

    if (du[1] == 4) cout << "2,2-dimethylbutane\n";
    else if (du[1] == 3 && du[2] == 3) cout << "2,3-dimethylbutane\n";
    else if (du[1] == 3) {
        int p = 0;
        for (int i = 1; i <= 6; i++) if (g[i].size() == 3) p = i;
        int total = 0;
        if (g[g[p][0]].size() == 1) total++;
        if (g[g[p][1]].size() == 1) total++;
        if (g[g[p][2]].size() == 1) total++;
        if (total == 1) cout << "3-methylpentane\n";
        else cout << "2-methylpentane\n";
    } else {
        cout << "n-hexane\n";
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