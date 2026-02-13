#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        int n, ans = 0;
        cin >> n;
        if (n == 0) break;
        for (int i = -n; i < 0; i++) {
            for (int j = -n; j < 0; j++) {
                if (i * i + j * j <= n * n) {
                    ans++;
                }
            }
        }
        ans = ans * 4 + n * 4 + 1;
        cout << ans << "\n";
    }
}