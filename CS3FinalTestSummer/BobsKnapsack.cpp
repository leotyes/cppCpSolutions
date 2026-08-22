#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> vn, psa;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            vn.push_back(x);
        }
    }
    psa.resize(vn.size() + 1);
    sort(vn.begin(), vn.end(), greater<>());
    for (int i = 1; i <= vn.size(); i++) {
        psa[i] = psa[i - 1] + vn[i - 1];
    }
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << psa[min(k, (int)psa.size() - 1)] << '\n';
    }
}