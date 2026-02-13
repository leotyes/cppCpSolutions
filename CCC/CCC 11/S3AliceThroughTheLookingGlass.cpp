#include <bits/stdc++.h>
using namespace std;

vector<int> vp = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};
set<pair<int, int>> sa = {{1, 0}, {2, 0}, {3, 0}, {2, 1}}, sp = {{1, 1}, {2, 2}, {3, 1}};

void look(int cl, int x, int y, int il) {
    if (il == 1) {
        if (sa.find(make_pair(x, y)) != sa.end()) {
            cout << "crystal\n";
        } else {
            cout << "empty\n";
        }
    } else {
        if (sa.find(make_pair(x / vp[il - 1], y / vp[il - 1])) != sa.end()) {
            cout << "crystal\n";
            return;
        }
        if (sp.find(make_pair(x / vp[il - 1], y / vp[il - 1])) == sp.end()) {
            cout << "empty\n";
            return;
        }
        look(cl + 1, x % vp[il - 1], y % vp[il - 1], il - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    while (t--) {
        int m, x, y;
        cin >> m >> x >> y;
        look(1, x, y, m);
    }
}