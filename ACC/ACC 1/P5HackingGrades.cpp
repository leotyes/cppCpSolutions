#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> vn(n), vd(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vd[i];
    }

    priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>> pq;

    for (int i = 0; i < n; i++) {
        pq.emplace((double)(vn[i] + 1) / (vd[i] + 1) - (double)vn[i] / vd[i], vn[i], vd[i]);
    }

    for (int i = 0; i < k; i++) {
        auto [v, n, d] = pq.top();
        pq.pop();
        pq.emplace((double)(n + 2) / (d + 2) - (double)(n + 1) / (d + 1), n + 1, d + 1);
    }

    double ans = 0;

    while (!pq.empty()) {
        auto [v, n, d] = pq.top();
        ans += (double)n / d;
        pq.pop();
    }

    ans /= n;
    ans *= 100;

    cout << fixed << setprecision(16) << ans;
}