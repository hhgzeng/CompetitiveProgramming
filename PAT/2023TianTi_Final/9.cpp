#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0, top = 0;
    stack<int> stk1, stk2;
    for (int i = 1; i <= n; i++) {
        if (stk1.empty()) stk1.push(a[i]);
        else if (a[i] < stk1.top()) stk1.push(a[i]);
        else if (stk2.empty()) stk2.push(a[i]);
        else if (a[i] > stk2.top()) stk2.push(a[i]);
        else {
            ans++;
            top = max(top, int(stk1.size()));
            while (!stk1.empty()) stk1.pop();
            while (!stk2.empty() && a[i] < stk2.top()) stk1.push(stk2.top()), stk2.pop();
            stk1.push(a[i]);
        }
    }
    if (!stk1.empty()) ans++, top = max(top, int(stk1.size()));
    if (!stk2.empty()) ans++, top = max(top, int(stk2.size()));
    cout << ans << " " << top;
    
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