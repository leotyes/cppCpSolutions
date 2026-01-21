#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n;

        cin >> n;

        if (n == 0) break;

        vector<int> vto(n + 1);
        vector<bool> vis(n + 1);
        long long ans = 1;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            vto[a] = b;
        }

        for (int i = 1; i <= n; i++) {
            vector<int> vc;
            int cur = i;

            while (!vis[cur]) {
                vc.push_back(cur);
                vis[cur] = true;
                cur = vto[cur];
            }

            if (vc.size()) ans = lcm(ans, vc.size());
        }

        cout << ans << "\n";
    }
}