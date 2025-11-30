#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<tuple<int, int, int>> ve, vn, vt;
    vector<int> ans(n, 0), init(n, -2);

    for (int i = 0; i < n; i++) {
        int x, y;
        char d;
        cin >> d >> x >> y;
        if (d == 'E') {
            ve.emplace_back(i, x, y);
        } else {
            vn.emplace_back(i, x, y);
        }
    }

    for (int i = 0; i < ve.size(); i++) {
        int ri = get<0>(ve[i]), x = get<1>(ve[i]), y = get<2>(ve[i]);
        for (int j = 0; j < vn.size(); j++) {
            int t1 = get<1>(vn[j]) - x, t2 = y - get<2>(vn[j]);
            if (t1 < 0 || t2 < 0 || t1 == t2) {
                continue;
            }
            vt.emplace_back(t1, ri, get<0>(vn[j]));
            vt.emplace_back(t2, get<0>(vn[j]), ri);
        }
    }

    sort(vt.begin(), vt.end());

    for (int i = 0; i < vt.size(); i++) {
        if (ans[get<1>(vt[i])] > 0) {
            continue;
        }
        if (ans[get<1>(vt[i])] == -1 && init[get<1>(vt[i])] == get<2>(vt[i])) {
            ans[get<1>(vt[i])] = get<0>(vt[i]);
        }
        if (init[get<2>(vt[i])] == -2) {
            init[get<2>(vt[i])] = get<1>(vt[i]);
            ans[get<2>(vt[i])] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            cout << "Infinity" << "\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
}