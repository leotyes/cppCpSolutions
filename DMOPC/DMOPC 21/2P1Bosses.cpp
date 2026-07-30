#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h, p, ans;
    cin >> n >> h >> p;
    vector<int> va(n), pre(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    sort(va.begin(), va.end());
    for (int i = 1; i <= n; i++) {
        pre[i] = va[i - 1] + pre[i - 1];
    }
    ans = pre[n] * p;
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && va[i] == va[i + 1]) continue;
        ans = min(ans, h * va[i] + p * ((pre[n] - pre[i + 1]) - va[i] * (n - i - 1)));
    }
    cout << ans << '\n';
}