#include <bits/stdc++.h>

using i64 = long long;

struct Info {
    int x;
    int y;
};

Info operator+(const Info &a, const Info &b) {
    return {a.x + b.x, a.y + b.y};
}

// partition
void part() {
    std::vector<int> numbers = {5, 20, 15, 10, 3, 8, 25};

    auto newEnd = std::partition(numbers.begin(), numbers.end(), [](int value) { 
        return value > 10;
    });

    // 打印结果
    for (auto it = numbers.begin(); it != newEnd; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "and the rest: ";
    for (auto it = newEnd; it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
}

// inplace_merge()
void inplace() {
    std::vector<int> v = {1, 3, 5, 2, 4, 6};
    auto middle = std::next(v.begin(), 3); // 指向第4个元素，即2
    std::sort(v.begin(), middle); // 排序前三个元素
    std::sort(std::next(middle), v.end()); // 排序后三个元素
    std::inplace_merge(v.begin(), middle, v.end()); // 合并两个有序序列
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " \n"[i == v.size() - 1];
    }
}

// hypot() 求斜边长
void hy() {
    std::array<int, 2> a{1, 2}, b{2, 3};
    std::cout << std::hypot(a[0] - b[0], a[1] - b[1]) << "\n";
}

void get_rand() {
    std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < 10; i++) {
        std::cout << rng() % 100 + 1 << "\n";
    }
}

void tan() {
    double a = 1.0, b = 1.0;
    double c1 = std::atan2(a, b); // 区别象限   (-π, π)
    double c2 = std::atan(a / b); // 不区分象限 (-π / 2, π / 2) 
}

void lambda() {
    // set lambda
    std::set<Info, decltype([](auto a, auto b) {
        return a.x != b.x ? a.x > b.x : a.y > b.y;
    })> st;
    // map lambda
    std::map<int, int, decltype([](auto a, auto b) {
		return a > b;
	})> mp;
    // priority_queue lambad
    std::priority_queue<int, std::vector<int>, std::function<bool(int, int)>> pq([&](auto a, auto b) {
		return a > b;
	});
}

void bs() {
    constexpr int N = 8;
    std::bitset<N> bs;
    bs.set(1); // parameter is null, every bit is 1, else pos is one
    bs.reset(2); // parameter is null, every bit is 0, else pos is zero
    bs.flip(1); // parameter is null, every bit is opposite, else pos is opposite
    std::cout << bs.count() << "\n";
    std::cout << bs[0] << "\n";
    std::cout << bs << "\n";
}

void permutation() { // 
    // std::string s = "123"; // begin must be ordered
    std::vector<int> s {1, 2, 3};
    do {
        for (int i = 0; i < s.size(); i++) {
            std::cout << s[i] << " \n"[i == s.size() - 1];
        }
    } while (next_permutation(s.begin(), s.end())); // permutaion
}

void getnext() {
    std::string s = "123";
    do {
        std::cout << s << "\n";        
    } while (next_permutation(s.begin(), s.end()));
}

struct Node {
    static constexpr int N = 1E9;
    static int add(int a, int b) {
        return a + b;
    }

    static int add(int a, int b, int c) {
        return add(1, 2);
    }
};

void solve() {
    
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