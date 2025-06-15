#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m1 = -1, m2 = -1;
    unordered_map<int, set<pair<int, int>>> mc;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        mc[a].insert({1, i});
    }

    for (int i = 1; i <= n; ++i) {
        int b;
        cin >> b;
        mc[b].insert({i, 1});
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            int fa = -1, fb = -1;
            for (auto& [k, v] : mc) {
                if (fa == -1 && v.find({i - 1, j}) != v.end()) {
                    fa = k;
                    if (fb != -1) {
                        break;
                    }
                }
                if (fb == -1 && v.find({i, j - 1}) != v.end()) {
                    fb = k;
                    if (fa != -1) {
                        break;
                    }
                }
            }
            mc[max(fa, fb)].insert({i, j});
        }
    }

    for (auto& [k, v] : mc) {
        if ((int)v.size() >= m1) {
            m1 = (int)v.size();
            m2 = max(m2, k);
        }
    }
    cout << m2 << " " << m1;
    return 0;
}