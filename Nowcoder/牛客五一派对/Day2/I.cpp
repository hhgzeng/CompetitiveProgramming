#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int a[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int cnt = 0, i = 1;
    while (a[i] == 0) {
        cnt++;
        i++;
    }

    int num = a[i++];
    string s;
    s.push_back(a[i++] + '0');
    while (cnt--) s.push_back('0');
    while (i <= n) {
        s.push_back(a[i] + '0');
        i++;
    }

    reverse(s.begin(), s.end());
    auto mul = [&]() -> string {
        string res;
        int carry = 0;
        for (int i = 0; i < s.size(); i++) {
            carry += (s[i] - '0') * num;
            res.push_back('0' + carry % 10);
            carry /= 10;
        }
        if (carry) res.push_back('0' + carry);
        reverse(res.begin(), res.end());
        return res;
    };
    cout << mul() << '\n';
    
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