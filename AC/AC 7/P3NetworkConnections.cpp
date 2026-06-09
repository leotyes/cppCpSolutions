#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> vf(n + 1);
    vector<pair<int, int>> vw(n);
    vp.resize(n + 1);
    for (int i = 1; i <= n; i++) vp[i] = i;
    for (int i = 1; i <= n; i++) {
        cin >> vf[i];
        vw[i - 1] = make_pair(vf[i], i);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int pcx = parent(x), pcy = parent(y);
        if (pcx != pcy) {
            vp[pcx] = pcy;
        }
    }

    sort(vw.begin(), vw.end());
    int ans = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    for (int i = 0; i < n - 1; i++) {
        auto [wx, x] = vw[i];
        auto [wy, y] = vw[i + 1];
        int pcx = parent(x), pcy = parent(y);
        if (pcx != pcy) {
            pq.emplace(abs(wx - wy), x, y);
        }
    }

    while (!pq.empty()) {
        auto [w, x, y] = pq.top();
        pq.pop();
        int pcx = parent(x), pcy = parent(y);
        if (pcx != pcy) {
            ans += w;
            vp[pcx] = pcy;
        }
    }

    cout << ans << "\n";
}