#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m;

    vector<vector<int>> vadj(n + 1, vector<int>());
    vector<bool> vvis(n + 1);
    int vis = 0, ans = -1;

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        vadj[a].push_back(b);
        vadj[b].push_back(a);
    }

    cin >> k;
    queue<pair<int, int>> q;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        q.emplace(x, 1);
        vis++;
        vvis[x] = true;
    }

    while (!q.empty()) {
        for (int x : vadj[q.front().first]) {
            if (!vvis[x]) {
                vvis[x] = true;
                vis++;
                q.emplace(x, q.front().second + 1);
            }
            if (vis == n) {
                break;
            }
        }
        if (vis == n) {
            ans = q.front().second;
            break;
        }
        q.pop();
    }

    cout << ans;
}