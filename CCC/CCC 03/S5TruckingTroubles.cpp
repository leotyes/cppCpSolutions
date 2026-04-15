#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c, r, d;
    cin >> c >> r >> d;
    priority_queue<tuple<int, int, int>> pq;
    vector<int> vd(c + 1, 0);
    vd[1] = 1;
    vp.resize(c + 1);
    for (int i = 1; i <= c; i++) {
        vp[i] = i;
    }
    for (int i = 0; i < r; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        pq.emplace(w, x, y);
    }
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        vd[x] = 1;
    }
    int ans = INT_MAX;
    while (!pq.empty()) {
        auto [w, x, y] = pq.top();
        pq.pop();
        int pcx = parent(x), pcy = parent(y);
        if (pcx != pcy) {
            vp[pcx] = pcy;
            vd[pcy] += vd[pcx];
            ans = min(ans, w);
            if (vd[pcy] == d + 1) {
                break;
            }
        }
    }

    cout << ans;
}