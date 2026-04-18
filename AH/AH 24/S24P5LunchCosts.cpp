#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c, p;
    cin >> n >> c >> p;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    int lo = 0, hi = *max_element(vn.begin(), vn.end()), ans = 0;
    while (lo < hi) {
        int mid = (lo + hi) / 2, cc = c * mid * n, cn = c * (mid + 1) * n;
        for (int i = 0; i < n; i++) {
            if (vn[i] > mid) {
                cc += (vn[i] - mid) * p;
            }
        }
        for (int i = 0; i < n; i++) {
            if (vn[i] > mid + 1) {
                cn += (vn[i] - (mid + 1)) * p;
            }
        }
        if (cc < cn) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    ans += c * lo * n;
    for (int i = 0; i < n; i++) {
        if (vn[i] > lo) {
            ans += (vn[i] - lo) * p;
        }
    }
    cout << ans;
}