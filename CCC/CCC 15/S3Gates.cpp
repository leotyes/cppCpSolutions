#include <bits/stdc++.h>
using namespace std;

int Gates() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int g, p;

    cin >> g >> p;

    set<int> gates;

    for (int i = 1; i <= g; i++) {
        gates.insert(i);
    }

    for (int i = 0; i < p; i++) {
        int m;
        cin >> m;

        auto it = gates.upper_bound(m);

        if (it == gates.begin()) {
            cout << i << "\n";
            return 0;
        } else {
            --it;
            gates.erase(it);
        }
    }
    cout << p;
}