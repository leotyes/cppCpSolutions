#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, err = 1e18 + 1;
    cin >> n;
    vector<int> vans(n + 1);
    if (n % 2 == 0) {
        for (int i = 1; i <= n; i += 2) {
            cout << "? " << i << ' ' << i + 1 << endl;
            int aj, d;
            cin >> aj;
            if (aj == err) return 0;
            cout << "? " << i << ' ' << i + 1 << endl;
            cin >> d;
            if (d == err) return 0;
            vans[i + 1] = d / 2;
            vans[i] = vans[i + 1] + aj;
        }
    } else {
        for (int i = 1; i < n; i += 2) {
            cout << "? " << i << ' ' << i + 1 << endl;
            int aj, d;
            cin >> aj;
            if (aj == err) return 0;
            cout << "? " << i << ' ' << i + 1 << endl;
            cin >> d;
            if (d == err) return 0;
            vans[i + 1] = d / 2;
            vans[i] = vans[i + 1] + aj;
        }
        cout << "? 1 " << n << endl;
        int aj;
        cin >> aj;
        if (aj == err) return 0;
        vans[n] = 2 * vans[1] - aj;
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << vans[i];
        if (i != n) cout << ' ';
    }
    cout << '\n';
}