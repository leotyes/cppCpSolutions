#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int m, ct = 0;

    cin >> m;

    vector<int> vt(101, 0), vs(101, -1);
    bool prev = false;

    for (int i = 0; i < m; i++) {
        char c;
        int x;

        cin >> c >> x;

        if (c == 'R') {
            if (i != 0 && !prev) {
                ct++;
            }
            vs[x] = ct;
            prev = false;
        } else if (c == 'S') {
            if (i != 0 && !prev) {
                ct++;
            }
            vt[x] += ct - vs[x];
            prev = false;
            vs[x] = -1;
        } else if (c == 'W') {
            ct += x;
            prev = true;
        }
    }

    for (int i = 0; i < 101; i++) {
        if (vs[i] != -1) {
            cout << i << " " << -1 << "\n";
        } else if (vt[i] != 0) {
            cout << i << " " << vt[i] << "\n";
        }
    }
}