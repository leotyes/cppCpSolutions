#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, a = 0, b = 1000001;
    cin >> k;
    if (a * (a - 1) / 2 + b * (b - 1) / 2 < k) {
        cout << -1 << '\n';
        return 0;
    }

    bool f = false;
    for (; a <= 1000001; a++) {
        int cur = a * (a - 1) / 2 + b * (b - 1) / 2;
        while (cur > k && b > 0) {
            b--;
            cur = a * (a - 1) / 2 + b * (b - 1) / 2;
        }
        if (cur == k) {
            f = true;
            break;
        }
    }

    if (!f || a + b > 1000001) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> vans;

    if (k == (int)1000000 * 1000001 / 2) swap(a, b);

    for (int i = 0; i < a - 1; i++) {
        vans.push_back(0);
    }

    if (b != 0) {
        vans.push_back(1);
    }

    for (int i = 0; i < b - 1; i++) {
        vans.push_back(0);
    }

    cout << vans.size() << '\n';
    for (int i = 0; i < vans.size(); i++) {
        cout << vans[i];
        if (i != vans.size() - 1) cout << ' ';
    }
    cout << '\n';
}