#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vp.resize(n + 1);
    for (int i = 1; i < n + 1; i++) vp[i] = i;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        if (s[x - 1] == s[y - 1]) {
            int pcx = parent(x), pcy = parent(y);
            vp[pcx] = pcy;
        }
    }
    vector<int> vans(m, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (s[a - 1] == c || s[b - 1] == c) {
            vans[i] = 1;
            continue;
        }
        if (parent(a) == parent(b)) {
            continue;
        }
        vans[i] = 1;
    }
    for (int x : vans) {
        cout << x;
    }
}