#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int ss, ts, ans = 0, m = LLONG_MAX;
    string s, t;
    cin >> ss >> ts >> s >> t;
    vector<int> freqs(26, 0);
    for (char c : s) {
        freqs[c - 'A']++;
    }
    for (char c : t) {
        m = min(m, freqs[c - 'A']);
        ans += freqs[c - 'A'];
    }
    ans += -m + *max_element(freqs.begin(), freqs.end());
    cout << ans << '\n';
}