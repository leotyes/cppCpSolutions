#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> dp(5, 0), ndp(5, 0);
    dp[0] = 1;
    ndp[0] = 1;
    map<char, int> mc = {{'G', 1}, {'A', 2}, {'N', 3}, {'?', 4}};

    for (char x : s) {
        if (mc[x] == 1) {
            ndp[1] += dp[0];
            ndp[1] %= 998244353;
            ndp[4] += dp[3];
            ndp[4] %= 998244353;
        } else if (mc[x] != 4) {
            ndp[mc[x]] += dp[mc[x] - 1];
            ndp[mc[x]] %= 998244353;
        } else {
            ndp[0] *= 3;
            ndp[1] *= 3;
            ndp[2] *= 3;
            ndp[3] *= 3;
            ndp[4] *= 3;
            for (int i = 0; i < 5; i++) {
                ndp[i] %= 998244353;
            }
            ndp[1] += dp[0];
            ndp[2] += dp[1];
            ndp[3] += dp[2];
            ndp[4] += dp[3];
            for (int i = 0; i < 5; i++) {
                ndp[i] %= 998244353;
            }
        }
        dp = ndp;
    }

    cout << ndp[4];
}