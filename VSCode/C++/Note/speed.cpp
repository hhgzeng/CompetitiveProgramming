#include <bits/stdc++.h>

using i64 = long long;

struct Info {
	int x;
	int y;
};

Info operator+(const Info &a, const Info &b) {
    return {a.x + b.x, a.y + b.y};
}

void solve1() {
    std::set<Info, decltype([](auto a, auto b) {
        return a.x != b.x ? a.x > b.x : a.y > b.y;
    })> st;
    st.insert({1, 2});
    st.insert({2, 3});
    st.insert({2, 4});
    st.insert({3, 1});

    for (auto [x, y] : st) {
    	std::cout << x << " " << y << "\n";
    }
}

void solve2() {
	std::map<int, int, decltype([](auto a, auto b) {
		return a > b;
	})> mp;
	mp[1] = 2;
	mp[2] = 3;
	for (auto [x, y] : mp) {
		std::cout << x << " " << y << "\n";
	}
}

void solve() {
	std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> pq([&](auto a, auto b) {
		return a > b;
	});
	pq.push(1);
	pq.push(2);
	pq.push(3);
	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		std::cout << x << "\n";
	}
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