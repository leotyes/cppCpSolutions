#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, l = 0, ans = 0;
    cin >> n >> k;
    unordered_map<int, int> cfreq;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) cin >> vn[i];
    for (int r = 0; r < n; r++) {
        cfreq[vn[r]]++;
        while (cfreq.size() >= k) {
            ans += n - r;
            cfreq[vn[l]]--;
            if (cfreq[vn[l]] == 0) {
                cfreq.erase(vn[l]);
            }
            l++;
        }
    }
    cout << ans << '\n';
}