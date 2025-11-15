#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, i, h, m;
    set<pair<int, int>> s;

    cin >> n >> i >> h >> m;

    vector<int> ans(n, h);

    for (int k = 0; k < m; k++) {
        int a, b;

        cin >> a >> b;


        if (s.find(make_pair(a, b)) != s.end()) {
            continue;
        }

        s.insert(make_pair(a, b));

        for (int j = min(a, b); j < max(a - 1, b - 1); j++) {
            ans[j] -= 1;
        }
    }

    for (int k = 0; k < n; k++) {
        cout << ans[k] << "\n";
    }
}