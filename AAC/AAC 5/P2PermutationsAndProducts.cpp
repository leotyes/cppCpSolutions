#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> vn(n - 1);

    for (int i = 2; i <= n; i++) {
        cout << "? 1 " << i << "\n";
        cout << flush;
        cin >> vn[i - 2];
        cout << flush;
    }

    if (*max_element(vn.begin(), vn.end()) == n) {
        cout << "! 1";
        for (int x : vn) {
            cout << " " << x;
        }
        cout << "\n";
        return 0;
    } else {
        int vmin = *min_element(vn.begin(), vn.end());
        cout << "! " << vmin;
        for (int x : vn) {
            cout << " " << x / vmin;
        }
        cout << "\n";
        return 0;
    }
}