#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, r = 0, ans = 0;
    cin >> n >> k;
    vector<int> vn(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    freq[vn[0]]++;
    for (int l = 0; l < n; l++) {
        while (freq.size() < k) {
            if (r == n - 1) {
                break;
            }
            r++;
            freq[vn[r]]++;
        }
        if (freq.size() >= k) {
            ans += n - r;
        }
        freq[vn[l]]--;
        if (freq[vn[l]] == 0) freq.erase(vn[l]);
    }
    cout << ans << '\n';
}