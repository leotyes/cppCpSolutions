#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, p, q;
    cin >> n;
    vector<tuple<int, int, int, int>> vr;

    for (int i = 1; i <= n; ++i) {
        int x, y, w, h;
        cin >> x >> y >> w >> h;
        vr.emplace_back(x, y, x + w, y + h);
    }

    cin >> p >> q;

    for (int i = n - 1; i >= 0; --i) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = vr[i];
        
        if (p >= x1 && p <= x2 && q >= y1 && q <= y2) {
            cout << i + 1;
            return 0;
        }
    }

    cout << "-1";
    return 0;
}