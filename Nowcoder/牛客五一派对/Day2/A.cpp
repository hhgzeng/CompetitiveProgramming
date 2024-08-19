#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pos(n);

    auto mul = [&](string s) -> string {
        string res;
        int carry = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            carry += (s[i] - '0') * 2;
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    };

    auto add = [&](string s, string t) -> string {
        string res;
        int carry = 0;
        int n = s.size(), m = t.size();
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        for (int i = 0; i < max(n, m); i++) {
            if (i < n) carry += s[i] - '0';
            if (i < m) carry += t[i] - '0';
            res.push_back(carry % 10 + '0');
            carry /= 10;
        }
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    };

    auto dfs = [&](auto && dfs, int l, int r) -> int {
        int res = 0;
        for (int i = l; i < r; i++) {
            if (s[i] == '2') {
                if (s[i + 1] == '(') {
                    res += 1 << dfs(dfs, pos[pos[i + 1]], pos[i + 1]);
                    i = pos[i + 1];
                } else {
                    res += 2;
                }
            }
        }
        return res;
    };

    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') stk.push(i);
        if (s[i] == ')') {
            pos[i] = stk.top();
            pos[stk.top()] = i;
            stk.pop();
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            if (s[i + 1] == '(') {
                int pw = dfs(dfs, pos[pos[i + 1]], pos[i + 1]);
                string temp = "1";
                while (pw--) temp = mul(temp);
                ans = add(ans, temp);
                i = pos[i + 1];
            } else {
                ans = add(ans, "2");
            }
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