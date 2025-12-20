#include <bits/stdc++.h>
using namespace std;

long long quickpow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base % mod);
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    long long mod = 1000000007;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, c, k;

        cin >> a >> b >> c >> k;

        if (b - a == c - b) {
            cout << (a % mod + ((k - 1) % mod) * ((b - a) % mod)) % mod << "\n";
        } else {
            long long mult = quickpow(1LL * b / a, k - 1, mod);
            cout << (a * mult) % mod << "\n";
        }
    }
}