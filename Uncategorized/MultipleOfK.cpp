#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> vn(n), psa(n + 1, 0), vsub(n + 1, 0);
    unordered_map<int, vector<int>> mpos;

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        psa[i + 1] = psa[i] + vn[i];
        vsub[i + 1] = psa[i + 1] % k;
    }

    for (int i = 0; i <= n; i++) {
        mpos[vsub[i]].push_back(i);
    }

    for (auto [x, v] : mpos) {
        ans = max(ans, v[v.size() - 1] - v[0]);
    }

    cout << ans;
}