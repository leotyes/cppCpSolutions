#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;
    vp.resize(n + 1);
    unordered_map<int, int> mans;
    for (int i = 1; i <= n; i++) vp[i] = i;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int px = parent(x), py = parent(y);
        if (px != py) {
            vp[px] = vp[py];
        }
    }

    for (int x : vp) {
        mans[parent(x)]++;
    }

    for (auto [k, v] : mans) {
        ans = max(ans, v);
    }

    cout << ans;
}