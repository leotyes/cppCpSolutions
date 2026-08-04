#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum += b[i];
        }

        if (sum <= 0) {
            cout << -1 << "\n";
            continue;
        }
        
        multiset<int> ms(b.begin(), b.end());
        vector<int> ans(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            auto it = ms.upper_bound(-s);
            int x = *it;
            ms.erase(it);
            s += x;
            ans[i] = s;
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}