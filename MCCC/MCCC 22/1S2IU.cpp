#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    string s;
    cin >> n >> s;
    vector<int> vi;
    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == 'I') vi.push_back(i);
    }
    for (int i = 0; i < 2 * n; i += 2) {
        ans += llabs(vi[i / 2] - i);
    }
    cout << ans << '\n';
}