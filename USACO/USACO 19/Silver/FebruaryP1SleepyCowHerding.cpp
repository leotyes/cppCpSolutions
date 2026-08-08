#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, amax = 0, amin = LLONG_MAX, l = 0;
    cin >> n;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) cin >> vn[i];
    sort(vn.begin(), vn.end());
    amax = max(vn[n - 2] - vn[0] - 1 - (n - 3), vn[n - 1] - vn[1] - 1 - (n - 3));
    for (int r = 0; r < n; r++) {
        while (l < r && vn[r] - vn[l] + 1 > n) l++;
        amin = min(amin, n - (r - l + 1));
    }
    if (vn[n - 1] - vn[1] == n - 2 && vn[1] - vn[0] > 2) amin = 2;
    if (vn[n - 2] - vn[0] == n - 2 && vn[n - 1] - vn[n - 2] > 2) amin = 2;
    cout << amin << '\n' << amax << '\n';
}