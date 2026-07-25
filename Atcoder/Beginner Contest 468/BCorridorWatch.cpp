#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, d, ans = 0;
    string s;
    cin >> m >> d >> s;
    vector<int> vd(m + 1), psa(m + 1);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'G') {
            vd[max(0, i - d)]++;
            vd[min(m, i + d + 1)]--;
        }
    }
    psa[0] = vd[0];
    for (int i = 1; i < m + 1; i++) {
        psa[i] = psa[i - 1] + vd[i];
    }
    for (int x : psa) {
        if (x == 0) ans++;
    }
    ans--;
    cout << ans;
}