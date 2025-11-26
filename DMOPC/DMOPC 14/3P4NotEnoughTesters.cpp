#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    vector<int> vf(1000001, 1);

    vf[0] = 0;

    for (int i = 2; i <= 1000000; i++) {
        int c = i;
        while (c <= 1000000) {
            vf[c]++;
            c += i;
        }
    }

    map<int, vector<int>> mk;

    for (int i = 2; i <= 1000000; i++) {
        mk[vf[i]].push_back(i);
    }

    for (int i = 0; i < t; i++) {
        int k, a, b;

        cin >> k >> a >> b;

        if (k == 1) {
            if (a == 1) {
                cout << 1 << "\n";
                continue;
            } else {
                cout << 0 << "\n";
                continue;
            }
        }

        if (mk.find(k) == mk.end()) {
            cout << 0 << "\n";
            continue;
        }

        cout << upper_bound(mk[k].begin(), mk[k].end(), b) - lower_bound(mk[k].begin(), mk[k].end(), a) << "\n";
    }
}