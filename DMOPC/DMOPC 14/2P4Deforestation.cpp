#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n;

    vector<int> psa(n);

    for (int i = 0; i < n; i++) {
        int mi;

        cin >> mi;

        psa[i] = (i == 0 ? mi : psa[i - 1] + mi);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int a, b;

        cin >> a >> b;

        if (a - 1 == -1) {
            cout << psa[b] << "\n";
        } else {
            cout << psa[b] - psa[a - 1] << "\n";
        }
    }
}