#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        vector<int> vn(3);
        cin >> vn[0] >> vn[1] >> vn[2];
        while (vn[0] != vn[1] && vn[1] != vn[2] && vn[0] != vn[2]) {
            (*max_element(vn.begin(), vn.end()))--;
            (*min_element(vn.begin(), vn.end()))++;
            ans++;
        }
        cout << ans << '\n';
    }
}