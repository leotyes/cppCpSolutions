#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p, q;
    cin >> n;
    map<tuple<int, int>, int> mc;

    for (int i = 1; i <= n; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        for (int j = x; j <= x + w; ++j) {
            for (int k = y; k <= y + h; ++k) {
                mc[{j, k}] = i;
            }
        }
    }

    cin >> p >> q;
    if (mc.find({p, q}) != mc.end()) {
        cout << mc[{p, q}];
    } else {
        cout << "-1";
    }
    return 0;
}