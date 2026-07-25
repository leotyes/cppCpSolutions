#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    bool b = false;
    cin >> n;
    vector<int> vp(n), vq(n);
    for (int i = 0; i < n; i++) {
        cin >> vp[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> vq[i];
    }
    do {
        ans++;
        if (vp == vq) {
            b = ans != 1;
            break;
        }
    } while (next_permutation(vp.begin(), vp.end()));
    if (!b) {
        cout << 0;
    } else {
        cout << ans - 2;
    }
}