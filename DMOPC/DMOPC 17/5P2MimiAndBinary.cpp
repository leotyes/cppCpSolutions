#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    vector<int> psa1(s.length()), psa0(s.length());

    psa1[0] = s[0] == '1' ? 1 : 0;

    for (int i = 1; i < s.size(); i++) {
        psa1[i] = psa1[i - 1] + (s[i] == '1' ? 1 : 0);
    }

    psa0[0] = s[0] == '0' ? 1 : 0;

    for (int i = 1; i < s.size(); i++) {
        psa0[i] = psa0[i - 1] + (s[i] == '0' ? 1 : 0);
    }

    int q;

    cin >> q;

    for (int i = 0; i < q; i++) {
        int x, y, z;

        cin >> x >> y >> z;

        if (z == 1) {
            auto find1 = lower_bound(psa1.begin() + x - 1, psa1.end(), y + (x == 1 ? 0 : psa1[x - 2]));
            if (find1 == psa1.end()) {
                cout << -1 << "\n";
            } else {
                cout << find1 - psa1.begin() + 1 << "\n";
            }
        } else {
            auto find0 = lower_bound(psa0.begin() + x - 1, psa0.end(), y + (x == 1 ? 0 : psa0[x - 2]));
            if (find0 == psa0.end()) {
                cout << -1 << "\n";
            } else {
                cout << find0 - psa0.begin() + 1 << "\n";
            }
        }
    }
}