#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> memo;

ll bu(ll cur) {
    ll cost = 0;
    if (memo.find(cur) != memo.end()) {
        return memo[cur];
    }
    if (cur >= 2) {
        cost += cur;
        if (cur % 2 == 0) {
            cost += 2 * bu(cur / 2);
        } else {
            cost += bu(cur / 2);
            cost += bu(cur / 2 + 1);
        }
        memo[cur] = cost;
        return cost;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;

    cin >> n;
    memo[1] = 0;

    cout << bu(n);
}