#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0, l = 0, cur = 0;
    cin >> n >> m;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }

    for (int r = 0; r < n; r++) {
        cur += vn[r];
        while (cur >= m && l <= r) {
            cur -= vn[l];
            l++;
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans;
}