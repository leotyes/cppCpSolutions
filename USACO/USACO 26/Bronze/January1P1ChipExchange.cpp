#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int a, b, ca, cb, fa;

        cin >> a >> b >> ca >> cb >> fa;

        if (fa <= a + (b / cb) * ca) {
            cout << 0 << "\n";
            continue;
        }

        a += b / cb * ca;
        b = b % cb;

        int ans = cb - 1 - b;

        if (ca >= cb) ans += fa - a;
        else if ((fa - a) % ca == 0) ans += ((fa - a - ca) / ca) * cb + ca;
        else {
            ans += (fa - a) / ca * cb + (fa - a) % ca;
        }

        cout << ans << "\n";
    }
}