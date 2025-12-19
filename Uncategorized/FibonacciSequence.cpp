#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll MOD = 1000000007;

pair<ll, ll> fib(ll cur) {
    if (cur == 0) return {0, 1};
    auto p = fib(cur >> 1);
    ll a = p.first;
    ll b = p.second;

    ll x = ((2 * b)%MOD - a%MOD + MOD) % MOD;
    ll c = ((__int128)a * x) % MOD;
    ll d = (((__int128)a * a) % MOD + ((__int128)b * b) % MOD) % MOD;

    if((cur & 1) == 0) {
        return {c, d};
    } else {
        return {d, (ll)((__int128)c + d) % MOD};
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;

    cout << fib(n).first;
}