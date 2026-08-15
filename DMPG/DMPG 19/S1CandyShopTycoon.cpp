#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, n;
    bool f = false;
    cin >> a >> b >> c >> n;
    for (int ha = 0; ha <= 100; ha++) {
        for (int hb = 0; hb <= 100; hb++) {
            for (int hc = 0; hc <= 100; hc++) {
                if (ha * a + hb * b + hc * c == n) {
                    f = true;
                    break;
                }
            }
        }
    }
    if (f) {
        cout << "QUEST CLEARED\n";
    } else {
        cout << "TRY AGAIN\n";
    }
}