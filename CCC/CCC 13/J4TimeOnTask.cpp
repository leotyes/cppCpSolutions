#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, c, ans = 0;

    cin >> t >> c;
    vector<int> vc(c);

    for (int i = 0; i < c; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end(), greater<int>());

    for (int i = 0; i < c; i++) {
        t -= vc.back();
        vc.pop_back();
        if (t < 0) {
            break;
        }
        ans++;
    }

    cout << ans;
}