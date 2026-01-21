#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vadj;
vector<int> vis;
int maxd = -1, endd, ans = -1;

void dfs(int cur, int curl, bool a) {
    for (int x : vadj[cur]) {
        if (!vis[x]) {
            vis[x] = true;
            if (curl + 1 > maxd && !a) {
                maxd = curl + 1;
                endd = x;
            }
            if (a) {
                ans = max(ans, curl + 1);
            }
            dfs(x, curl + 1, a);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vadj.resize(n + 1, vector<int>());
    vis.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        vadj[x].push_back(y);
        vadj[y].push_back(x);
    }

    vis[1] = true;
    dfs(1, 0, false);

    for (int i = 0; i <= n; i++) {
        vis[i] = false;
    }

    dfs(endd, 0, true);

    cout << ans;
}