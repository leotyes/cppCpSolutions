#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a0, b, m, mod = 1e9 + 7, s, ans = 0;
    cin >> n >> a0 >> b >> m;
    b %= m;
    s = 0;
    int prev = a0;
    for (int i = 0; i < n; i++) {
        ans += (prev * s) % mod;
        ans %= mod;
        s += prev;
        s %= mod;
        prev = (prev * b) % m;
    }
    cout << (ans * 2) % mod << '\n';
}