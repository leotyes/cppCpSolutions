#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    vector<int> ti(t);
    set<int> sp;

    for (int i = 0; i < t; i++) {
        cin >> ti[i];
    }

    vector<bool> vp(2000005, true);

    for (int i = 2; i < 2000004; i++) {
        if (vp[i]) {
            int c = 2 * i;
            sp.insert(i);

            while (c < vp.size()) {
                vp[c] = false;
                c += i;
            }
        }
    }

    for (int i = 0; i < t; i++) {
        for (int p : sp) {
            if (sp.find(ti[i] * 2 - p) != sp.end()) {
                cout << p << " " << ti[i] * 2 - p << "\n";
                break;
            }
        }
    }
}