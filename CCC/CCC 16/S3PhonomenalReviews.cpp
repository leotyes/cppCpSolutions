// prune the tree using a recursive function returning true and false
// then the answer is just 2 times edges minus diameter length
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> va;
vector<bool> vn;
int ss, ds, dmax = -1;

bool dfs(int cr, int p) {
    if (p == -1) {
        for (int i = 0; i < va[cr].size(); i++) {
            dfs(va[cr][i], cr);
        }
        return true;
    }
    if (va[cr].size() == 1) {
        if (vn[cr]) {
            return true;
        }
        return false;
    }
    bool r = false;
    if (vn[cr]) {
        r = true;
    }
    for (int i = 0; i < va[cr].size(); i++) {
        if (va[cr][i] == p) continue;
        if (dfs(va[cr][i], cr)) r = true;
    }
    if (r) {
        vn[cr]= true;
        ss = cr;
    }
    return r;
}

void ddfs(int c, bool t, int p, int curd) {
    for (int i = 0; i < va[c].size(); i++) {
        if (!vn[va[c][i]]) continue;
        if (va[c][i] == p) continue;
        if (curd + 1 > dmax) {
            dmax = curd + 1;
            if (!t) ds = va[c][i];
        }
        ddfs(va[c][i], t, c, curd + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;

    cin >> n >> m;

    va.resize(n, vector<int>());
    vn.resize(n, false);

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        vn[x] = true;
        s = x;
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        va[a].push_back(b);
        va[b].push_back(a);
    }

    dfs(s, -1);
    ddfs(ss, false, -1, 0);
    dmax = -1;
    ddfs(ds, true, -1, 0);
    int e = 0;

    for (int i = 0; i < n; i++) {
        if (vn[i]) e++;
    }

    e--;

    cout << 2 * e - dmax;
}