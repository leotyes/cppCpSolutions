#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, cmax = 0, ans = 0;

    cin >> n >> m;

    vector<bool> av(m, true);

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        for (int j = 0; j < m; j++) {
            if (s[j] == 'x') {
                av[j] = false;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (av[i] == true) {
            cmax++;
        } else {
            ans = max(ans, cmax);
            cmax = 0;
        }
    }

    cout << max(ans, cmax);
}