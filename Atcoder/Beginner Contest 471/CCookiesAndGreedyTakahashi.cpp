#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, pn = 0, pp = 0, ans = 0;
    cin >> n;
    vector<int> vn, vp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            vp.push_back(x);
        } else {
            vn.push_back(x);
        }
    }
    sort(vp.begin(), vp.end());
    sort(vn.begin(), vn.end(), greater<>());
    int prev = 0;
    while (pn != vn.size() || pp != vp.size()) {
        if (pn == vn.size()) {
            ans += vp[pp] - prev;
            prev = vp[pp];
            pp++;
        } else if (pp == vp.size()) {
            ans += prev - vn[pn];
            prev = vn[pn];
            pn++;
        } else {
            int pc = vp[pp] - prev, nc = prev - vn[pn];
            if (pc == nc || nc < pc) {
                ans += nc;
                prev = vn[pn];
                pn++;
            } else {
                ans += pc;
                prev = vp[pp];
                pp++;
            }
        }
    }
    cout << ans;
}