#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, r, c;

    cin >> n >> m >> r >> c;

    if (r != n && c != m || (n == r && m == c)) {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < m; j++) {
                cout << 'x';
            }
            cout << '\n';
        }
        for (int i = 0; i < n - r; i++) {
            for (int j = 0; j < c; j++) {
                cout << 'x';
            }
            for (int j = 0; j < m - c; j++) {
                cout << 'y';
            }
            cout << '\n';
        }
    } else if (m == c) {
        if (n % 2 == 0 && r % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }

        vector<vector<int>> vg(n, vector<int>(m, 'x'));
        if (n % 2 == 0) {
            for (int i = 0; i < (n - r) / 2; i++) {
                vg[i][0] = 'y';
                vg[n - i - 1][0] = 'y';
            }
        } else if (r % 2 == 0) {
            vg[n / 2][0] = 'y';
            for (int i = 0; i < (n - r) / 2; i++) {
                vg[i][0] = 'y';
                vg[n - i - 1][0] = 'y';
            }
        } else if (r % 2 == 1) {
            for (int i = 0; i < (n - r) / 2; i++) {
                vg[i][0] = 'y';
                vg[n - i - 1][0] = 'y';
            }
        }
        for (auto v : vg) {
            for (char x : v) cout << x;
            cout << '\n';
        }
    } else if (n == r) {
        if (m % 2 == 0 && c % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        if (m % 2 == 0) {
            vector<char> vf(m, 'x');
            for (int i = 0; i < (m - c) / 2; i++) {
                vf[i] = 'y';
                vf[m - i - 1] = 'y';
            }
            for (char x : vf) cout << x;
            cout << '\n';
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) cout << 'x';
                cout << '\n';
            }
        } else if (c % 2 == 0) {
            vector<char> vf(m, 'x');
            vf[m / 2] = 'y';
            for (int i = 0; i < (m - c) / 2; i++) {
                vf[i] = 'y';
                vf[m - i - 1] = 'y';
            }
            for (char x : vf) cout << x;
            cout << '\n';
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) cout << 'x';
                cout << '\n';
            }
        } else if (c % 2 == 1) {
            vector<char> vf(m, 'x');
            for (int i = 0; i < (m - c) / 2; i++) {
                vf[i] = 'y';
                vf[m - i - 1] = 'y';
            }
            for (char x : vf) cout << x;
            cout << '\n';
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < m; j++) cout << 'x';
                cout << '\n';
            }
        }
    }
}