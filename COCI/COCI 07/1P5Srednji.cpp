#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b, s;
    cin >> n >> b;

    vector<int> vn(n), vb(n, 0), psa(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        if (vn[i] > b) {
            vb[i] = 1;
        } else if (vn[i] < b) {
            vb[i] = -1;
        } else {
            s = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i - 1] + vb[i - 1];
    }

    int ans = 0;

    map<int, int> mp;
    for (int i = 0; i <= s; i++) {
        mp[psa[i]]++;
    }

    for (int i = s + 1; i <= n; i++) {
        ans += mp[psa[i]];
    }

    cout << ans;
}