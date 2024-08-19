#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 5;

void solve()
{   
    int a;
    cin >> a;
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int b;
    cin >> b;

    int ans = b - a + 1;
    for (int i = 1; i <= n; i++) {
        if (a <= v[i] && v[i] <= b) {
            ans--;
        }
    }
    cout << ans << '\n';
    
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