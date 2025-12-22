#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;

    cin >> n;

    vector<int> vb(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (i == 0) {
            ans += vb[0];
            ans += min(vb[0], vb[1]);
        } else if (i == n - 2) {
            ans += vb[i];
        } else {
            ans += min(vb[i], vb[i + 1]);
        }
    }

    cout << ans;
}