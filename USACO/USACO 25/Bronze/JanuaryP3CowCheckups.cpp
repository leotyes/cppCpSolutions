#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> va(n), vb(n), valr, vans(n + 1);
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> vb[i];
        if (vb[i] == va[i]) {
            valr.push_back(i);
        }
    }

    for (int len = 0; len < n; len++) {
        for (int j = 0; j < n - len; j++) {
            if (len == 0) {
                if (va[j] == vb[j]) {
                    dp[j][j + len] = 1;
                }
            } else {
                dp[j][j + len] = dp[j + 1][j + len - 1];
                if (va[j] == vb[j + len]) {
                    dp[j][j + len]++;
                }
                if (vb[j] == va[j + len]) {
                    dp[j][j + len]++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int lo = lower_bound(valr.begin(), valr.end(), i) - valr.begin();
        for (int j = i; j < n; j++) {
            int hi = upper_bound(valr.begin(), valr.end(), j) - valr.begin(), curans = valr.size() - hi + lo;

            curans += dp[i][j];
            vans[curans]++;
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << vans[i] << "\n";
    }
}