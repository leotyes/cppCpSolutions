#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int r, c, q;
    set<int> rs, cs;

    cin >> r >> c;

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char ci;

            cin >> ci;

            if (ci == 'X') {
                rs.insert(i);
                cs.insert(j);
            }
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int xi, yi;

        cin >> xi >> yi;

        if (rs.find(yi) != rs.end() || cs.find(xi) != cs.end()) {
            cout << "Y" << "\n";
        } else {
            cout << "N" << "\n";
        }
    }
}