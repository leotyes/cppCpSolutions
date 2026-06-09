#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int r1, r2, r3, total, valid;
        cin >> r1 >> r2 >> r3;
        total = (r2 - r3) * (r2 - r3);
        if (r1 <= r3) {
            valid = min(r2 - r3, r3 - r1) * min(r2 - r3, r3 - r1);
        } else {
            valid = (r1 - r3) * (r1 - r3);
        }
        valid += max(0LL, total - (r1 + r3) * (r1 + r3));

        double ans = (double)valid / total;
        cout << ans << '\n';
    }
}