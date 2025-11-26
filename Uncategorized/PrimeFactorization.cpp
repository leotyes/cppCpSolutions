#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        string ans;

        cin >> x;

        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                if (ans.empty()) {
                    ans = to_string(j);
                } else {
                    ans += " " + to_string(j);
                }
                x /= j;
            }
        }

        if (ans.empty()) {
            cout << x << "\n";
        } else {
            if (x != 1) {
                cout << ans << " " << x << "\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
}