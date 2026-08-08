#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vp(m);
    for (int i = 0; i < m; i++) {
        cin >> vp[i].first >> vp[i].second;
    }

    int a = vp[0].first, b = vp[0].second;
    set<pair<int, int>> ans;
    set<int> possible;
    bool f = false;

    for (int i = 1; i < m; i++) {
        int x = vp[i].first;
        int y = vp[i].second;

        if (a == x || a == y) {
            continue;
        }

        if (!f) {
            possible.insert(x);
            possible.insert(y);
            f = true;
        } else {
            set<int> temp;
            for (int v : possible) {
                if (v == x || v == y) {
                    temp.insert(v);
                }
            }
            possible = temp;
        }
    }

    if (!f) {
        for (int x = 1; x <= n; x++) {
            if (x != a) {
                ans.insert({min(a, x), max(a, x)});
            }
        }
    } else {
        for (int x : possible) {
            if (x != a) {
                ans.insert({min(a, x), max(a, x)});
            }
        }
    }

    possible.clear();
    f = false;

    for (int i = 1; i < m; i++) {
        int x = vp[i].first;
        int y = vp[i].second;

        if (b == x || b == y) {
            continue;
        }

        if (!f) {
            possible.insert(x);
            possible.insert(y);
            f = true;
        } else {
            set<int> temp;

            for (int v : possible) {
                if (v == x || v == y) {
                    temp.insert(v);
                }
            }

            possible = temp;
        }
    }

    if (!f) {
        for (int x = 1; x <= n; x++) {
            if (x != b) {
                ans.insert({min(b, x), max(b, x)});
            }
        }
    } else {
        for (int x : possible) {
            if (x != b) {
                ans.insert({min(b, x), max(b, x)});
            }
        }
    }

    cout << ans.size() << '\n';
}