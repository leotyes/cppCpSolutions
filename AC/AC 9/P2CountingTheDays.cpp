#include <bits/stdc++.h>
using namespace std;
#define int long long

int fpow(int b, int p, int mod) {
    int cur = 1;
    for (int i = 0; i < p; i++) {
        cur *= b;
        cur %= mod;
    }
    return cur;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ans = -1;
        bool bz = false;
        cin >> n;
        vector<int> vs(n), temp;
        vector<vector<int>> vsp;
        for (int i = 0; i < n; i++) {
            cin >> vs[i];
            if (vs[i] == 0) {
                bz = true;
                if (!temp.empty()) {
                    vsp.push_back(temp);
                }
                temp.clear();
            } else {
                temp.push_back(vs[i]);
            }
        }

        if (!temp.empty()) vsp.push_back(temp);

        if (n == 1) {
            if (vs[0] < 0) {
                cout << 998244353 + vs[0] << "\n";
            } else {
                cout << vs[0] << "\n";
            }
            continue;
        }

        if (vsp.empty()) {
            cout << "0\n";
            continue;
        }

        for (auto v : vsp) {
            bool bn = false;
            int twos = 0;
            for (int i = 0; i < v.size(); i++) {
                if (abs(v[i]) == 2) twos++;
                if (v[i] < 0) bn = not bn;
            }
            if (!bn) {
                ans = max(ans, twos);
                continue;
            }

            if (v.size() == 1) {
                if (v[0] == 1) {
                    ans = max(ans, 0LL);
                } else if (v[0] == 2) {
                    ans = max(ans, 1LL);
                }
                continue;
            }

            int pans = 0, sans = 0;

            for (int i = 0; i < v.size(); i++) {
                if (abs(v[i]) == 2) pans++;
                if (v[i] < 0) break;
            }

            for (int i = v.size() - 1; i >= 0; i--) {
                if (abs(v[i]) == 2) sans++;
                if (v[i] < 0) break;
            }
            ans = max(twos - min(pans, sans), ans);
        }

        if (ans == -1) {
            cout << "0\n";
        } else {
            cout << fpow(2, ans, 998244353) << "\n";
        }
    }
}