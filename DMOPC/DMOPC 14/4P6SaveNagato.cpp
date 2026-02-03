#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vadj;
vector<int> vd1, vd2;
int dmax = -1, ds, de;

void dfs(int c, int cd, int cp, int t) {
    if (t == 0) {
        if (cd > dmax) {
            ds = c;
            dmax = cd;
        }
        for (int i : vadj[c]) {
            if (i == cp) continue;
            dfs(i, cd + 1, c, t);
        }
    } else if (t == 1) {
        if (cd > dmax) {
            de = c;
            dmax = cd;
        }
        for (int i : vadj[c]) {
            if (i == cp) continue;
            vd1[i] = cd + 1;
            dfs(i, cd + 1, c, t);
        }
    } else if (t == 2) {
        for (int i : vadj[c]) {
            if (i == cp) continue;
            vd2[i] = cd + 1;
            dfs(i, cd + 1, c, t);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vadj.resize(n + 1, vector<int>());
    vd1.resize(n + 1);
    vd2.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        vadj[a].push_back(b);
        vadj[b].push_back(a);
    }

    dfs(1, 0, -1, 0);
    dmax = -1;
    vd1[ds] = 0;
    dfs(ds, 0, -1, 1);
    vd2[de] = 0;
    dfs(de, 0, -1, 2);

    for (int i = 1; i <= n; i++) {
        cout << max(vd1[i], vd2[i]) + 1 << "\n";
    }
}