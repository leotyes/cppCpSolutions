#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k;

    cin >> t >> k;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;

        vector<int> vans(3 * n, 2);

        if (n % 2 == 1) {
            cout << -1 << "\n";
            continue;
        }

        if (string(s.begin(), s.begin() + 3 * n / 2) == string(s.begin() + 3 * n / 2, s.end())) {
            cout << 1 << "\n";
            for (int i = 0; i < 3 * n; i++) {
                cout << 1 << " ";
            }
            cout << "\n";
            continue;
        }

        string l = string(s.begin(), s.begin() + 3 * n / 2), r = string(s.begin() + 3 * n / 2, s.end());

        for (int i = 0; i < 3 * n / 2; i += 3) {
            string a = string(l.begin() + i, l.begin() + i + 3), b = string(r.begin() + i, r.begin() + i + 3);
            if (a[0] == b[0]) {
                vans[i] = 1;
                vans[i + 1] = 1;
                vans[i + 2] = 1;
                vans[i + 3 * n / 2] = 1;
                vans[i + 3 * n / 2 + 1] = 1;
                vans[i + 3 * n / 2 + 2] = 1;
            } else if (a[0] == b[1]) {
                vans[i + 2] = 1;
                vans[i + 3 * n / 2] = 1;
            } else if (a[0] == b[2]) {
                vans[i] = 1;
                vans[i + 3 * n / 2 + 2] = 1;
            }
        }

        cout << 2 << "\n";

        for (int x : vans) {
            cout << x << " ";
        }
        cout << "\n";
    }
}