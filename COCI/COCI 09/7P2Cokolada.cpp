#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, e, init, ans = 0;
    cin >> k;
    e = ceil(log(k)/log(2));
    init = pow(2, e);

    cout << init << " ";

    if (init == k) {
        cout << 0;
        return 0;
    }

    while (k != 0) {
        init /= 2;
        if (init <= k) {
            k -= init;
        }
        ans++;
    }

    cout << ans;
}