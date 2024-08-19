#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        string s1, s2, t;
        cin >> a >> b >> s1 >> s2;
        int n1 = s1.size();
        int n2 = s2.size();
        b = b - a + 1;
        t = s.substr(a - 1, b);
        s.erase(a - 1, b);
        bool flag = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s.substr(i, n1) == s1 && s.substr(i + n1, n2) == s2) {
                s.insert(i + n1, t);
                flag = 0;
                break;
            }
        }
        if (flag) s.insert(s.size(), t);
    }
    cout << s << "\n";
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