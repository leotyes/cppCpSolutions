#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 998244353;
vector<int> fact, invfact;

int quickpow(int base, int exp) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int choose(int n, int k) {
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, ans = 0, sum = 0, ssum = 0;
    cin >> n >> k;
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % mod;
    invfact[n] = quickpow(fact[n], mod - 2);
    for (int i = n; i >= 1; i--) invfact[i - 1] = (invfact[i] * i) % mod;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        ans += (choose(n - 1, k - 1) * quickpow(vn[i], 2)) % mod;
        ans %= mod;
        sum += vn[i] % mod;
        sum %= mod;
        ssum += quickpow(vn[i], 2);
        ssum %= mod;
    }
    int diff = (quickpow(sum, 2) - ssum % mod + mod) % mod;
    if (k >= 2) {
        ans = (ans + diff * choose(n - 2, k - 2)) % mod;
    }
    ans %= mod;
    cout << ans;
}