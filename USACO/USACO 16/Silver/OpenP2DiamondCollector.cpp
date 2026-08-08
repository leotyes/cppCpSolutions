#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, r = 0, ans = 0;
    cin >> n >> k;
    vector<int> vn(n), pre(n, 0), suf(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    sort(vn.begin(), vn.end());
    for (int l = 0; l < n; l++) {
        if (r == n) {
            break;
        }
        pre[r] = pre[(r == 0 ? 0 : r - 1)];
        while (vn[r] - vn[l] <= k) {
            pre[r] = max(pre[r], r - l + 1);
            r++;
            if (r == n) break;
            pre[r] = max(pre[r], pre[(r == 0 ? 0 : r - 1)]);
        }
    }
    r = 0;
    reverse(vn.begin(), vn.end());
    for (int l = 0; l < n; l++) {
        if (r == n) {
            break;
        }
        suf[n - r - 1] = suf[(n - r - 1 == n - 1 ? n - 1 : n - r)];
        while (vn[l] - vn[r] <= k) {
            suf[n - r - 1] = max(suf[n - r - 1], r - l + 1);
            r++;
            if (r == n) break;
            suf[n - r - 1] = max(suf[n - r - 1], suf[(n - r - 1 == n - 1 ? n - 1 : n - r)]);
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, pre[i] + suf[i]);
    }
    if (ans > n) ans = n;
    cout << ans << '\n';
}