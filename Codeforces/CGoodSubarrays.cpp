#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        string s;
        cin >> n >> s;
        vector<int> psa(n + 1, 0), psasub(n + 1, 0);
        for (int i = 0; i < n; i++) {
            psa[i + 1] = s[i] - '0' + psa[i];
        }
        for (int i = 1; i <= n; i++) {
            psasub[i] = psa[i] - i;
        }
        unordered_map<int, int> mfreq;
        for (int i = 0; i <= n; i++) {
            ans += mfreq[psasub[i]];
            mfreq[psasub[i]]++;
        }
        cout << ans << '\n';
    }
}