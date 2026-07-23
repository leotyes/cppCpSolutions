#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> vr(n + 1, 0), vc(n + 1, 0);
    while (m--) {
        int r, c;
        cin >> r >> c;
        int prer = vc[c], prec = vr[r];
        vc[prec] = 0;
        vr[prer] = 0;
        vr[r] = c;
        vc[c] = r;
    }
    for (int i = 1; i <= n; i++) {
        if (vr[i] != 0) ans++;
    }
    cout << ans;
}