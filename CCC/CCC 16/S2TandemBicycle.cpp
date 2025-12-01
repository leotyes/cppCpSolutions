#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, n, ans = 0;

    cin >> t >> n;

    vector<int> dmoj(n), peg(n);

    for (int i = 0; i < n; i++) {
        cin >> dmoj[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> peg[i];
    }

    if (t == 1) {
        sort(dmoj.begin(), dmoj.end());
        sort(peg.begin(), peg.end());
        for (int i = 0; i < n; i++) {
            ans += max(dmoj[i], peg[i]);
        }
    } else {
        sort(dmoj.begin(), dmoj.end());
        sort(peg.begin(), peg.end(), greater<int>());
        for (int i = 0; i < n; i++) {
            ans += max(dmoj[i], peg[i]);
        }
    }

    cout << ans;
}