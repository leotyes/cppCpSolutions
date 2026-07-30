#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> vi(n + 1), vv(n + 1);
    for (int i = 0; i <= n; i++) {
        vi[i] = i;
        vv[i] = i;
    }
    for (int i = 0; i < q; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            int x, y;
            cin >> x >> y;
            swap(vv[x], vv[y]);
            vi[vv[x]] = x;
            vi[vv[y]] = y;
        } else if (c == 'E') {
            int x, y;
            cin >> x >> y;
            swap(vi[x], vi[y]);
            vv[vi[x]] = x;
            vv[vi[y]] = y;
        } else {
            vector<int> vq(n + 1), vans(n);
            for (int j = 1; j <= n; j++) {
                cin >> vq[j];
            }
            for (int j = 1; j <= n; j++) {
                vans[vi[j]] = vq[j];
            }
            for (int j = 1; j <= n; j++) {
                cout << vans[j];
                if (j == n) cout << '\n'; else cout << ' ';
            }
        }
    }
}