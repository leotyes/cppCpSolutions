#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;
    vector<int> vn(n), dp(n);
    for (int i = 0; i < n; i++) cin >> vn[i];
    dp[0] = vn[0];
    deque<pair<int, int>> dq;
    dq.emplace_back(dp[0], 0);
    for (int i = 1; i < n; i++) {
        dp[i] = dq.front().first + vn[i];
        while (!dp.empty() && dq.back().first >= dp[i]) {
            dq.pop_back();
        }
        dq.emplace_back(dp[i], i);
        if (dq.front().second <= i - d) dq.pop_front();
    }
    cout << dp[n - 1] << '\n';
}