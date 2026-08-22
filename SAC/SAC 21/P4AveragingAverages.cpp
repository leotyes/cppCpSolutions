#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> vn(n), psa(n + 1);
    psa[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        psa[i + 1] = psa[i] + vn[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << (psa[r] - psa[l - 1]) / (r - l + 1) << '\n';
    }
}