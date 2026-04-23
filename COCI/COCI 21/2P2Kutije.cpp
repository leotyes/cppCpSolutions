#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    vp.resize(n + 1);
    for (int i = 1; i <= n; i++) vp[i] = i;
    vector<vector<int>> vn(m, vector<int>(n + 1));
    vector<pair<int, int>> vadj;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> vn[i][j];
            vadj.emplace_back(j, vn[i][j]);
        }
    }

    for (auto [a , b] : vadj) {
        int pca = parent(a), pcb = parent(b);
        if (pca != pcb) {
            vp[pca] = vp[pcb];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (parent(a) == parent(b)) {
            cout << "DA\n";
        } else {
            cout << "NE\n";
        }
    }
}