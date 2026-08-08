#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, sum;
    cin >> n >> k;

    vector<int> vn(n), vk(k + 1), psa(n + 1, 0);
    vector<vector<int>> pos(k + 1);

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        psa[i + 1] = psa[i] + vn[i];
        pos[vn[i]].push_back(i);
    }

    sum = accumulate(vn.begin(), vn.end(), 0LL);

    for (int d = 1; d <= k; d++) {
        cin >> vk[d];

        int curk = vk[d], l = -1, r = -1, ans = sum;

        for (int i = pos[d].size() - 1; i >= 0; i--) {
            int j = pos[d][i];
            if (r == -1) {
                r = j;
            }
            if (l != -1) {
                l = max(0LL, l - curk - 1);
            } else {
                l = max(0LL, j - curk);
            }
            if (l == j || (i > 0 && pos[d][i - 1] < l)) {
                ans -= psa[r + 1] - psa[l];
                l = -1;
                r = -1;
            }
        }

        if (l != -1) {
            ans -= psa[r + 1] - psa[l];
        }

        cout << ans << '\n';
    }
}