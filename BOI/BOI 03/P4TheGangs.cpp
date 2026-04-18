#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

void unite(int a, int b) {
    a = parent(a);
    b = parent(b);
    int aa = min(a, b), bb = max(a, b);
    if (aa != bb) vp[bb] = aa;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vp.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) vp[i] = i;

    for (int i = 0; i < m; i++) {
        char t;
        int a, b;
        cin >> t >> a >> b;

        if (t == 'F') {
            unite(a, b);
        } else {
            unite(a, b + n);
            unite(b, a + n);
        }
    }

    set<int> g;
    for (int i = 1; i <= n; i++) g.insert(parent(i));

    cout << g.size() << '\n';
}