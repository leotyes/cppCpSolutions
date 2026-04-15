#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, set<int>> mx, my;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        mx[x].insert(y);
        my[y].insert(x);
        vp.emplace_back(x, y);
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int ix = vp[i].first, iy = vp[i].second;
        for (int j = i + 1; j < n; j++) {
            int jx = vp[j].first, jy = vp[j].second;
            if (mx.find(jx) != mx.end()) {
                if (mx[jx].find(iy) != mx[jx].end()) {
                    if (mx.find(ix) != mx.end()) {
                        if (mx[ix].find(jy) != mx[ix].end()) {
                            ans = max(ans, (long long)abs(jx - ix) * abs(jy - iy));
                        }
                    }
                }
            }
        }
    }

    cout << ans;
}