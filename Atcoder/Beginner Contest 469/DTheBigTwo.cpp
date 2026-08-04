#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a;
    bool b = true;
    cin >> n >> m;
    vector<bool> va(m, false), vb(m, false);
    vector<pair<int, int>> vp(m);
    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        vp.emplace_back(ai, bi);
    }
    a = vp[0].first;
    b = vp[0].second;
    set<int> sp;
    for (int i = 1; i < m; i++) {
        auto [ai, bi] = vp[i];
        if (a == ai || a == bi) {

        } else {
            b = false;
            if (sp.empty()) {
                sp.insert(ai);
                sp.insert(bi);
            }
        }
    }

    if (b)
}