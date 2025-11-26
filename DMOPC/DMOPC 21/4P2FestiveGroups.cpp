#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;

    cin >> n;

    set<int> sn;

    for (int i = 0; i < n; i++) {
        int x;

        cin >> x;

        sn.insert(x);
    }


    vector<bool> vp(*sn.rbegin() + 1, false);

    for (int x : sn) {
        if (!vp[x]) {
            ans++;
            for (int j = x; j <= *sn.rbegin(); j += x) {
                vp[j] = true;
            }
        }
    }

    cout << ans << "\n";
}