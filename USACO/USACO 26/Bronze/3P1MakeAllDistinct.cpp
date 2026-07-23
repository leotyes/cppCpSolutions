#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k, ans = 0;
        map<int, int> mfreq1;
        map<int, int, greater<>> mfreq2;
        cin >> n >> k;
        vector<int> vn(n);
        for (int i = 0; i < n; i++) {
            cin >> vn[i];
            if (k > 0) {
                mfreq1[vn[i]]++;
            } else {
                mfreq2[vn[i]]++;
            }

        }
        if (k > 0) {
            for (auto [x, f] : mfreq1) {
                if (f == 1) continue;
                mfreq1[x + k] += f - 1;
                ans += f - 1;
            }
        } else {
            for (auto [x, f] : mfreq2) {
                if (f == 1) continue;
                mfreq2[x + k] += f - 1;
                ans += f - 1;
            }
        }

        cout << ans << '\n';
    }
}