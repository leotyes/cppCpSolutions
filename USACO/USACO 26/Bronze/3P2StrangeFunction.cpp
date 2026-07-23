#include <bits/stdc++.h>
using namespace std;
#define int long long

int quickpow(int base, int exp, int mod) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, MOD = 1000000007;
    cin >> t;
    while (t--) {
        string s;
        int ans = 1;
        bool b = false;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != '0' && c != '1') b = true;
            if ((c - '0') % 2 == 0) {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
        if (!b) ans = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            char c = s[i];
            int fs = s.size() - i - 1;
            if (c == '1') {
                if (fs == 0) {
                    ans++;
                    continue;
                }
                ans += 3 * quickpow(2, fs - 1, MOD);
                ans %= MOD;
            }
        }
        cout << ans << '\n';
    }
}