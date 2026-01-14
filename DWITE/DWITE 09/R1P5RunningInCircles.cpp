#include <bits/stdc++.h>
using namespace std;

set<int> vis;
map<int, vector<int>> m;
int ans = -1;

void dfs(int cur, int len) {
    for (int x : m[cur]) {
        if (vis.find(x) != vis.end()) {
            ans = len;
            return;
        } else {
            if (ans != -1) return;
            vis.insert(x);
            dfs(x, len + 1);
            vis.erase(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 5;

    while (t--) {
        int n;

        cin >> n;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            m[a].push_back(b);
        }

        dfs(1, 1);

        cout << ans - 1 << "\n";

        ans = -1;
        m.clear();
    }
}