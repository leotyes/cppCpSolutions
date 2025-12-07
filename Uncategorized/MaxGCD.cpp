#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ans = -1;

    cin >> n;

    vector<int> vn(n), pre(n), suf(n);

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }

    pre[0] = vn[0];
    for (int i = 1; i < n; i++) {
        pre[i] = gcd(pre[i - 1], vn[i]);
    }

    suf[n - 1] = vn[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = gcd(suf[i + 1], vn[i]);
    }

    ans = max(pre[n - 2], suf[1]);
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, gcd(pre[i - 1], suf[i + 1]));
    }

    if (n == 2) {
        cout << max(vn[0], vn[1]);
    } else {
        cout << ans;
    }
}