#include <bits/stdc++.h>
#define int __int128
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], n, m;

int exgcd(int b, int p, int &a, int &k)
{
    if (p == 0) {
        a = 1, k = 0;
        return b;
    }
    int g = exgcd(p, b % p, k, a);
    k -= b / p * a;
    return g;
}

int read()
{
    int x = 0;
    char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}

void print(int x)
{
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();

    int A = a[1], B = b[1];
    for (int i = 2; i <= n; i++) {
        int p, q;
        int g = exgcd(A, a[i], p, q);
        if ((B - b[i]) % g != 0) {
            cout << "he was definitely lying";
            return;
        }
        int t = a[i] / g;
        p = (p * ((b[i] - B) / g) % t + t) % t;
        B = A * p + B;
        A = A / g * a[i];
    }
    if (B > m) cout << "he was probably lying";
    else print(B);

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}