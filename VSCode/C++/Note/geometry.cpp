#include <bits/stdc++.h>

using i64 = long long;

struct Info {
	double x;
	double y;
};

// a相对于原点旋转p度
Info rotate(Info a, double p) {
    auto [x, y] = a;
    a.x = x * cos(p) - y * sin(p);
    a.y = x * sin(p) + y * cos(p);
    return a;
}

// a相对于b旋转p度
Info rotate(Info a, Info b, double p) {
    auto [x1, y1] = a;
    auto [x2, y2] = b;
    a.x = (x1 - x2) * cos(p) - (y1 - y2) * sin(p) + x2;
    a.x = (x1 - x2) * sin(p) + (y1 - y2) * cos(p) + y2;
    return a;
}

void solve() {
	int n;
	std::cin >> n;
	double a, b, r;
	std::cin >> a >> b >> r;
	a -= 2 * r, b -= 2 * r;

	constexpr double PI = 3.141592653589793;
	double p = std::atan(a / b);
	double R = std::hypot(a, b) / 2;

	std::vector<Info> v;
	for (int i = 0; i < n; i++) {
		double x, y, z;
		std::cin >> x >> y >> z;
		// v.emplace_back(Info{x + R * cos(p + z), y + R * sin(p + z)});
		// v.emplace_back(Info{x - R * cos(p + z), y - R * sin(p + z)});
		// v.emplace_back(Info{x + R * cos(-p + z), y + R * sin(-p + z)});
		// v.emplace_back(Info{x - R * cos(-p + z), y - R * sin(-p + z)});
		v.push_back({x + R * cos(p + z), y + R * sin(p + z)});
		v.push_back({x - R * cos(p + z), y - R * sin(p + z)});
		v.push_back({x + R * cos(z - p), y + R * sin(z - p)});
		v.push_back({x - R * cos(z - p), y - R * sin(z - p)});
	}
 
	int pos = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[pos].y >= v[i].y) {
			if (v[pos].y > v[i].y || v[pos].x > v[i].x) {
				pos = i;
			}
		}
	}
	std::swap(v[0], v[pos]);

	auto check = [&](Info a1, Info a2, Info b1, Info b2) -> double {
		return (a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x);
	};

	std::sort(v.begin() + 1, v.end(), [&](auto x, auto y) {
		double ok = check(v[0], x, v[0], y);
		if (ok > 0) {
			return 1;
		} else if (ok == 0 && std::hypot(v[0].x - x.x, v[0].y - x.y) < std::hypot(v[0].x - y.x, v[0].y - y.y)) {
			return 1;
		} else {
			return 0;
		}
	});

	std::vector<Info> stk;
	stk.emplace_back(v[0]);
	for (int i = 1; i < v.size(); i++) {
		int m = stk.size();
		while (m > 1 && check(stk[m - 2], stk[m - 1], stk[m - 1], v[i]) <= 0) {
			stk.pop_back();
			m--;
		}
		stk.emplace_back(v[i]);
	}
	stk.emplace_back(v[0]);

	double ans = 0.0;
	for (int i = 1; i < stk.size(); i++) {
		ans += std::hypot(stk[i].x - stk[i - 1].x, stk[i].y - stk[i - 1].y);
	}

	std::cout << std::fixed << std::setprecision(2);
	std::cout << ans + 2.0 * PI * r << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
    	solve();
    }

    return 0;
}