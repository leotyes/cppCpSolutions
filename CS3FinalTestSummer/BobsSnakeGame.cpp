#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
        dq.emplace_back(i, 0);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            char d;
            cin >> d;
            dq.pop_back();
            auto [cx, cy] = dq.front();
            if (d == 'U') {
                dq.emplace_front(cx, cy + 1);
            } else if (d == 'D') {
                dq.emplace_front(cx, cy - 1);
            } else if (d == 'R') {
                dq.emplace_front(cx + 1, cy);
            } else {
                dq.emplace_front(cx - 1, cy);
            }
        } else {
            int i;
            cin >> i;
            i--;
            cout << dq[i].first << ' ' << dq[i].second << '\n';
        }
    }
}