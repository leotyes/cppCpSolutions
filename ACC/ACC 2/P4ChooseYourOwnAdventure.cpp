#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    if (m > n + 1) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (i == n && n + 1 == m) {
            cout << n + i << " " << n + m;
        } else {
            cout << i + 1 << " " << min(n + i, n + m) << "\n";
        }
    }
}