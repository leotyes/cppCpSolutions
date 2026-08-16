#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q, v;
    cin >> q >> v;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < q; i++) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int tq, wq;
            cin >> tq >> wq;
            pq.push(tq - wq);
        } else {
            int tq;
            cin >> tq;
            if (pq.empty()) {
                cout << "-1\n";
                continue;
            }
            cout << min(v, tq - pq.top()) << '\n';
            pq.pop();
        }
    }
}