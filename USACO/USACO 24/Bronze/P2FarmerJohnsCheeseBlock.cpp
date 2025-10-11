#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q, ans = 0;

    cin >> n >> q;

    vector<vector<int>> xy(n, vector<int>(n, 0)), yz(n, vector<int>(n, 0)), xz(n, vector<int>(n, 0));

    for (int i = 0; i < q; i++) {
        int x, y, z;

        cin >> x >> y >> z;

        xy[x][y]++;
        yz[y][z]++;
        xz[x][z]++;

        if (xy[x][y] == n) {
            ans++;
        }
        if (yz[y][z] == n) {
            ans++;
        }
        if (xz[x][z] == n) {
            ans++;
        }
        cout << ans << "\n";
    }
}