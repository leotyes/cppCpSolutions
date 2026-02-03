#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    vector<long long> vd(100000, LLONG_MAX);

    for (int i = 0; i < n; i++) {
        cin >> vd[i];
    }

    for (int i = 0; i < 30; i++) {
        vd[i + 1] = min(vd[i + 1], 2 * vd[i]);
    }

    while (q--) {
        long long x, ans = LLONG_MAX, tcur = 0;
        cin >> x;
        for (int i = 30; i >= 0; i--) {
            if ((1LL << i) <= x) {
                tcur += vd[i];
                x -= (1LL << i);
            }
            ans = min(ans, tcur + vd[i]);
        }
        cout << min(ans, tcur) << "\n";
    }
}