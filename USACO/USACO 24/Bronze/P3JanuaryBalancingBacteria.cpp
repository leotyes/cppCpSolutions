#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0, adj = 0, moves = 0;
    cin >> n;
    vector<int> vn(n), vd1(n), vd2(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 0; i < n; i++) {
        vn[i] += adj;
        moves -= vn[i];
        adj += moves - vn[i];
        ans += llabs(vn[i]);
    }
    cout << ans;
}