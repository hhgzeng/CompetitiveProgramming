#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    string t;
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        string cnt;
        vector<string> words;
        for (int j = 0; j < s.size(); j++) {
            if (isupper(s[j]) || s[j] == '_') {
                if (!cnt.empty()) {
                    words.push_back(cnt);
                    cnt.clear();
                }
            }
            if (s[j] != '_') {
                cnt += tolower(s[j]);
            }
        }
        if (!cnt.empty()) words.push_back(cnt);
        s.clear();
        if (t == "Camel") {
            s += words[0];
            for (int j = 1; j < words.size(); j++) {
                words[j][0] = toupper(words[j][0]);
                s += words[j];
            }
        } else if (t == "Pascal") {
            for (int j = 0; j < words.size(); j++) {
                words[j][0] = toupper(words[j][0]);
                s += words[j];
            }
        } else {
            for (int j = 0; j < words.size() - 1; j++) {
                s += words[j];
                s += '_';
            }
            s += words[words.size() - 1];
        }
        cout << s << "\n";
    }

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