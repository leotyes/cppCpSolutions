#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> vr(n + 1), vc(m + 1);
    map<int, int> mr, mc;

    for (int i = 1; i <= n; i++) {
        cin >> vr[i];
        if (vr[i] != -1) {
            mr[vr[i] - i]++;
        }
    }

    for (int i = 1; i <= m; i++) {
        cin >> vc[i];
        if (vc[i] != -1) {
            mc[vc[i] - i]++;
        }
    }

    int ans = 0;

    for (auto [v, c] : mr) {
        ans += min(c, mc[v]);
    }

    cout << ans << "\n";
}