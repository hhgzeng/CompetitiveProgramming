// author : hhgzeng
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;

void solve()
{
    ll a, b;
    cin >> a >> b;
    
    vector<ll> dp(13), mi(13);
    mi[0] = 1;
    for (int i = 1; i <= 12; i++) {
        dp[i] = dp[i - 1] * 10 + mi[i - 1];
        mi[i] = 10 * mi[i - 1];
    }

    auto f = [&](ll r) -> vector<ll> {
        vector<ll> cnt(13), ans(10);
        int len = 0;
        ll temp = r;
        while (r) {
            cnt[++len] = r % 10;
            r /= 10;
        }

        for (int i = len; i >= 1; i--) {
            for (int j = 0; j < 10; j++) ans[j] += dp[i - 1] * cnt[i];
            for (int j = 0; j < cnt[i]; j++) ans[j] += mi[i - 1];
            temp -= cnt[i] * mi[i - 1];
            ans[cnt[i]] += temp + 1;
            ans[0] -= mi[i - 1];
        }

        return ans;
    };

    vector<ll> ans1 = f(a - 1);
    vector<ll> ans2 = f(b);
    for (int i = 0; i < 10; i++) cout << ans2[i] - ans1[i] << ' ';
    
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}