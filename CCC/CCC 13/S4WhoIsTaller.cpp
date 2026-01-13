#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vadj, radj;
int p, q;
bool more = false, bless = false;
set<int> pvisited, qvisited;

void dfs(int cur, int goal) {
    if (cur == goal) {
        if (goal == q) {
            more = true;
        } else {
            bless = true;
        }
        return;
    }
    if (goal == q) {
        if (pvisited.find(cur) != pvisited.end()) {
            return;
        }
        pvisited.insert(cur);
    } else {
        if (qvisited.find(cur) != qvisited.end()) {
            return;
        }
        qvisited.insert(cur);
    }
    for (int i = 0; i < vadj[cur].size(); i++) {
        if (more || bless) {
            return;
        }

        dfs(vadj[cur][i], goal);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vadj.resize(n + 1, vector<int>());
    radj.resize(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        vadj[x].push_back(y);
        radj[y].push_back(x);
    }

    cin >> p >> q;

    dfs(p, q);
    dfs(q, p);

    if (!more && !bless) {
        cout << "unknown";
    } else if (more) {
        cout << "yes";
    } else {
        cout << "no";
    }
}