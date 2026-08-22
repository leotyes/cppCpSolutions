#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> vn(n + 2), dp(n + 2), vans;
    for (int i = 1; i <= n; i++) {
        cin >> vn[i];
    }
    vn[n + 1] = 0;
    vn[0] = 0;
    dp[0] = 0;
    deque<pair<int, int>> dq;
    dq.emplace_back(dp[0], 0);
    for (int i = 1; i <= n + 1; i++) {
        dp[i] = dq.front().first + vn[i];
        while (!dq.empty() && dq.back().first >= dp[i]) {
            dq.pop_back();
        }
        dq.emplace_back(dp[i], i);
        if (dq.front().second <= i - k) dq.pop_front();
    }

    vector<int> dpr(n + 2);
    deque<pair<int, int>> dqr;
    dpr[n + 1] = 0;
    dqr.emplace_back(dpr[n + 1], n + 1);
    for (int i = n; i >= 0; i--) {
        dpr[i] = dqr.front().first + vn[i];
        while (!dqr.empty() && dqr.back().first >= dpr[i]) {
            dqr.pop_back();
        }
        dqr.emplace_back(dpr[i], i);
        if (dqr.front().second >= i + k) dqr.pop_front();
    }

    int cur = 0;
    while (cur != n + 1) {
        int r = min(n + 1, cur + k);
        for (int j = cur + 1; j <= r; j++) {
            if (dpr[j] == dp[n + 1] - dp[cur]) {
                if (j != n + 1) {
                    vans.push_back(j);
                }
                cur = j;
                break;
            }
        }
    }

    cout << dp[n + 1] << '\n';

    for (int x : vans) {
        cout << x << ' ';
    }
}