#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vprev;
vector<bool> vis;
int lc = 0;

void dfs(int cur, int curl) {
    for (int x : vprev[cur]) {
        if (!vis[x]) {
            vis[x] = true;
            lc = max(lc, curl + 1);
            dfs(x, curl + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, slow = 1, fast = 1, cy = 1;
    bool s = false;

    cin >> n;

    vector<int> next(n + 1), vc;
    vprev.resize(n + 1, vector<int>());
    vis.resize(n + 1, false);


    for (int i = 1; i <= n; i++) {
        cin >> next[i];
        vprev[next[i]].push_back(i);
    }

    while (slow != fast || !s) {
        s = true;
        slow = next[slow];
        fast = next[fast];
        fast = next[fast];
    }

    fast = 1;

    while (slow != fast) {
        slow = next[slow];
        fast = next[fast];
    }

    vc.push_back(fast);
    vis[fast] = true;
    fast = next[fast];

    while (slow != fast) {
        cy++;
        vis[fast] = true;
        vc.push_back(fast);
        fast = next[fast];
    }

    for (int x : vc) {
        dfs(x, 0);
    }

    cout << (cy + lc - 1) * 2;
}