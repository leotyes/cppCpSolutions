#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a1 = 0, a2 = 0;

    cin >> n >> m;

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    vector<vector<tuple<int, int, int>>> vadj(n + 1, vector<tuple<int, int, int>>());
    vector<bool> vd(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        vadj[a].emplace_back(d, c, b);
        vadj[b].emplace_back(d, c, a);
    }

    pq.emplace(0, 0, 1);

    while (!pq.empty()) {
        auto [cd, cc, cde] = pq.top();
        pq.pop();

        if (vd[cde]) continue;

        vd[cde] = true;
        a1 += cd;
        a2 += cc;

        for (auto x : vadj[cde]) {
            if (!vd[get<2>(x)]) pq.push(x);
        }
    }

    cout << a1 << " " << a2;
}