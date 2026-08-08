#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> vn(n), vl(1000001, INT_MAX), vr(1000001, -1);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        vl[vn[i]] = min(vl[vn[i]], i);
        vr[vn[i]] = max(vr[vn[i]], i);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (vl[a] == -1 || vr[b] == INT_MAX) continue;
        ans = max(ans, vr[b] - vl[a] + 1);
    }
    cout << ans;
}