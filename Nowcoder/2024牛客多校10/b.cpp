#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, q;
	std::cin >> n >> q;

	std::unordered_map<std::string, std::string> f;
	for (int i = 0; i < n; i++) {
		std::string s, t;
		std::cin >> s >> t;
		t.pop_back();
		f[t] = s;
	}

	while (q--) {
		std::string a;
		std::cin >> a;

		std::string t, p;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '.') {
				t += (a[i + 1] == 'f') ? "1" : "2";
			}
			if (t.empty()) {
				p += a[i];
			}
		}

		if (t.empty()) {
			std::cout << f[a] << "\n";
			continue;
		}

		std::string s = f[p];
		const int N = s.size();
		const int M = t.size();

		std::string ans;
		for (int i = 5, j = 0; i < N; j++) {
			if (t[j] == '2') {
				int cnt = 0;
				while (i < N) {
					if (s[i] == '<') {
						cnt++;
					}
					if (s[i] == '>') {
						cnt--;
					}
					if (s[i] == ',' && cnt == 0) {
						break;
					}
					i++;
				}
				assert(cnt == 0 && s[i] == ',');
				i++;
			}
			if (j + 1 == M) {
				int cnt = 0;
				if (s[i] == 'i') {
					ans = "int";
				} else if (s[i] == 'd') {
					ans = "double";
				} else {
					ans = "pair";
					i += 4;
					while (i < N) {
						ans += s[i];
						if (s[i] == '<') {
							cnt++;
						}
						if (s[i] == '>') {
							cnt--;
						}
						if (cnt == 0) {
							break;
						}
						i++;
					}
				}
				break;
			}
			i += 5;
		}
		std::cout << ans << "\n";
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    while (T--) {
    	solve();
    }

    return 0;
}