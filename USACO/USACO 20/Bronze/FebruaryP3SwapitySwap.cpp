#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, a1, a2, b1, b2;

    cin >> n >> k >> a1 >> a2 >> b1 >> b2;

    vector<int> vans(n + 1), vto(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i <= n; i++) vans[i] = i;

    vector<int> temp = vans;

    for (int i = a1; i <= a2; i++) {
        temp[i] = vans[a2 - i + a1];
    }

    vector<int> temp2 = temp;

    for (int i = b1; i <= b2; i++) {
        temp2[i] = temp[b2 - i + b1];
    }

    for (int i = 1; i <= n; i++) {
        vto[temp2[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
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