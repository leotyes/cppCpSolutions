#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;

    cin >> n;

    vector<int> c(n + 1), k(n);

    for (int i = 0; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    for (int i = 0; i < n; i++) {
        if (c[i] < k[i]) {
            ans += min(k[i], c[i] + c[i + 1]);
            c[i + 1] = max(0, c[i + 1] - k[i] + c[i]);
        } else {
            ans += k[i];
        }
    }

    cout << ans;
}