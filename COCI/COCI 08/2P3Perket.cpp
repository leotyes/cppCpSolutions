#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> sn, bn;
long long ans = LLONG_MAX;

void check(long long s, long long b, int k) {
    if (s != 1 && b != 0 && k != 0) {
        ans = min(ans, llabs(s - b));
    }
    if (k != n) {
        for (int i = k; i < n; i++) {
            check(s * sn[i], b + bn[i], i + 1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long s, b;
        cin >> s >> b;
        sn.push_back(s);
        bn.push_back(b);
    }

    if (n == 1) {
        cout << llabs(sn[0] - bn[0]);
    } else {
        check(1LL, 0LL, 0);
        cout << ans;
    }
}