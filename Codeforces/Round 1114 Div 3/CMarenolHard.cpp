#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ac = 0, bc = 0;
        string a, b;
        cin >> n >> a >> b;
        if (count(a.begin(), a.end(), '1') != count(b.begin(), b.end(), '1')) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && i % 2 == 0) ac += 1;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == '1' && i % 2 == 0) bc += 1;
        }
        if (ac != bc) {
            cout << "-1\n";
            continue;
        }
        vector<int> ae, ao, be, bo;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == '1') {
                if (i % 2 == 0) ae.push_back(i); else ao.push_back(i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == '1') {
                if (i % 2 == 0) be.push_back(i); else bo.push_back(i);
            }
        }
        for (int i = 0; i < ae.size(); i++) {
            ans += abs(ae[i] - be[i]) / 2;
        }
        for (int i = 0; i < ao.size(); i++) {
            ans += abs(ao[i] - bo[i]) / 2;
        }
        cout << ans << '\n';
    }
}