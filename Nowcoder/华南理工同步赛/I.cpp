#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vector<int> cnt1, cnt2;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') cnt1.push_back(i);
        else cnt2.push_back(i);
    }

    if (cnt1.size() == 0) {
        for (int i = 1; i < cnt2.size(); i++) cout << cnt2[0] << " " << cnt2[i] << "\n";
        cout << cnt2[1] << " " << cnt2[2] << "\n";
    } else if (cnt2.size() == 0) {
        for (int i = 1; i < cnt1.size(); i++) cout << cnt1[0] << " " << cnt1[i] << "\n";
        cout << cnt1[1] << " " << cnt1[2] << "\n";
    } else {
        cout << cnt1[0] << " " << cnt2[0] << "\n";
        for (int i = 1; i < cnt1.size(); i++) cout << cnt2[0] << " " << cnt1[i] << "\n";
        for (int i = 1; i < cnt2.size(); i++) cout << cnt1[0] << " " << cnt2[i] << "\n";
        if (cnt1.size() == 1) {
            cout << cnt2[0] << " " << cnt2[1] << "\n";
        } else if (cnt2.size() == 1) {
            cout << cnt1[0] << " " << cnt1[1] << "\n";
        } else {
            cout << cnt1[1] << " " << cnt2[1] << "\n";
        }
    }

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