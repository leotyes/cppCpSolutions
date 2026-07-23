#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ans = LONG_LONG_MAX;
        string s;
        cin >> n >> s;
        vector<int> prew(n, 0), prer(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == 'W') {
                if (i == 0) {
                    prew[i] = 1;
                } else {
                    prew[i] = prew[i - 1] + 1;
                    prer[i] = prer[i - 1];
                }
            } else {
                if (i == 0) {
                    prer[i] = 1;
                } else {
                    prew[i] = prew[i - 1];
                    prer[i] = prer[i - 1] + 1;
                }
            }
        }
        int mindiff = prew[0] - prer[0];
        for (int i = 1; i < n - 1; i++) {
            ans = min(ans, mindiff + prer[i] + prew[n - 1] - prew[i]);
            mindiff = min(mindiff, prew[i] - prer[i]);
        }
        cout << ans << '\n';
    }
}