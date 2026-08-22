#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans;
    cin >> n;
    ans = n * (n - 1) / 2;
    vector<int> vn(n);
    unordered_map<int, int> freqm;
    map<pair<int, int>, int> freqp;
    for (int i = 0; i < n; i++) {
        int m, b;
        cin >> m >> b;
        freqm[m]++;
        freqp[make_pair(m, b)]++;
    }
    for (auto [v, c] : freqm) {
        ans -= c * (c - 1) / 2;
    }
    for (auto [v, c] : freqp) {
        ans += c * (c - 1) / 2;
    }
    cout << ans;
}