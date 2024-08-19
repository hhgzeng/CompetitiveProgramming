#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    stack<array<int, 5>> stk;
    for (int i = n; i >= 1; i--) {
        int l = i, r = i, sum = a[i];
        int aver = a[i], res = 0, high = a[i];
        while (!stk.empty() && high <= stk.top()[1] + (stk.top()[2] > 0)) {
            array<int, 5> top = stk.top(); stk.pop();
            sum += top[0];
            r = top[4];
            aver = sum / (r - l + 1);
            res = sum % (r - l + 1);
            high = aver + (res > 0);
        }
        stk.push({sum, aver, res, l, r});
    }
    cout << stk.top()[1] + (stk.top()[2] > 0) << '\n';
    
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}