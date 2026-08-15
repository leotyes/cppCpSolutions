#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> vn(n, vector<int>(n));
    vector<int> vans;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cin >> vn[i][j];
        }
    }
    vans.push_back(0);
    for (int i = 1; i < n; i++) {
        int cand = vans[i - 1] + vn[i - 1][i];
        int cmin = cand, cmax = cand;
        for (int j = i - 1; j >= 0; j--) {
            cmin = min(cmin, vans[j]);
            cmax = max(cmax, vans[j]);
            if (cmax - cmin != vn[j][i]) {
                cand = vans[i - 1] - vn[i - 1][i];
                break;
            }
        }
        vans.push_back(cand);
    }
    for (int x : vans) {
        cout << x << ' ';
    }
}