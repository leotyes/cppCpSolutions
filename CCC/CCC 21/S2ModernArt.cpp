#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, ans = 0;

    cin >> m >> n >> k;

    vector<int> r(m + 1, 0), c(n + 1, 0);

    for (int i = 0; i < k; i++) {
        int num;
        string cr;

        cin >> cr >> num;

        if (cr == "R") {
            r[num] += 1;
        } else if (cr == "C") {
            c[num] += 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if ((r[i] + c[j]) % 2 == 1) {
                ans++;
            }
        }
    }

    cout << ans;
}