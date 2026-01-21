#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;

    cin >> n >> m >> k;

    vector<int> vto(n + 1), vans(n + 1);
    vector<bool> vis(n + 1, false);

    for (int i = 1; i <= n; i++) vans[i] = i;

    vector<int> temp = vans, temp2 = vans;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            temp[j] = temp2[b - j + a];
        }
        temp2 = temp;
    }

    for (int i = 1; i <= n; i++) {
        vto[temp2[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> vc;
        int cur = i;

        while (!vis[cur]) {
            vc.push_back(cur);
            vis[cur] = true;
            cur = vto[cur];
        }

        for (int j = 0; j < vc.size(); j++) {
            vans[vc[(j + k % vc.size()) % vc.size()]] = vc[j];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << vans[i] << "\n";
    }
}