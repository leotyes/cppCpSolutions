#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<vector<int>> va;
bool found = false;

void dfs(int cur, vector<bool>& visited) {
    if (cur == b) {
        found = true;
        return;
    }
    for (int x : va[cur]) {
        if (!visited[x] && !found) {
            visited[x] = true;
            dfs(x, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b;

    va.resize(n);
    a--;
    b--;

    for (int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;

        va[x - 1].push_back(y - 1);
        va[y - 1].push_back(x - 1);
    }

    vector<bool> visited(n);
    visited[a] = true;

    dfs(a, visited);

    if (found) {
        cout << "GO SHAHIR!";
    } else {
        cout << "NO SHAHIR!";
    }
}