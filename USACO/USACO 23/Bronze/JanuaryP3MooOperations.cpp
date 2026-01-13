#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;

    cin >> q;

    for (int i = 0; i < q; i++) {
        string s;

        cin >> s;

        int m = INT_MAX;

        for (int j = 0; j < (int)s.size(); j++) {
            int cur = 0;
            if (j < (int)s.size() - 2) {
                if (s[j + 1] == 'M') {
                    continue;
                } else {
                    if (s[j] == 'O') {
                        cur++;
                    }
                    if (s[j + 2] == 'M') {
                        cur++;
                    }
                    m = min(m, cur);
                    if (s[j] == 'M' && s[j + 2] == 'O') {
                        break;
                    }
                }
            } else {
                break;
            }
        }

        if (m == INT_MAX) {
            cout << -1 << "\n";
        } else {
            cout << m + (int)s.size() - 3 << "\n";
        }
    }
}