#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>

using namespace std;

const ll N = 1e5 + 5;

void solve()
{
    ll n;
    cin >> n;
    vector<pii> v(n + 1);

    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
        sum += v[i].second;
    }
    bool flag = sum & 1;
    sum /= 2;

    sort(v.begin() + 1, v.end());

    ll sum1 = 0, sum2 = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt >= sum) sum2 += v[i].first * v[i].second;
        else if (cnt + v[i].second <= sum) cnt += v[i].second, sum1 += v[i].first * v[i].second;
        else {
            if (flag) sum2 += (v[i].second - (sum - cnt) - 1) * v[i].first;
            else sum2 += (v[i].second - (sum - cnt)) * v[i].first;
            sum1 += (sum - cnt) * v[i].first, cnt = sum;
        }
    }

    cout << sum2 - sum1 << "\n";

}

int main()
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