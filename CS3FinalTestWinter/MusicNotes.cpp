#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    vector<int> va(n), psa(n);

    for (int i = 0; i < n; i++) {
        cin >> va[i];
        if (i == 0) {
            psa[0] = va[i] - 1;
        } else {
            psa[i] = psa[i - 1] + va[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int ti;

        cin >> ti;

        cout << lower_bound(psa.begin(), psa.end(), ti) - psa.begin() + 1 << "\n";
    }
}