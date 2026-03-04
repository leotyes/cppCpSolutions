#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, l, q;

    cin >> n >> l >> q;

    vector<ll> diff(n + 1, 0);
    vector<bool> ill(n + 1, false);

    for (ll i = 0; i < l; i++) {
        ll pi, si;
        cin >> pi >> si;
        diff[(pi - si >= 1 ? pi - si : 1)]++;
        if (pi + si < n) {
            diff[pi + si + 1]--;
        }
    }

    ll cur = 0;

    for (ll i = 1; i <= n; i++) {
        cur += diff[i];
        if (cur > 0) ill[i] = true;
    }

    for (ll i = 0; i < q; i++) {
        ll x;
        cin >> x;
        if (ill[x]) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
}