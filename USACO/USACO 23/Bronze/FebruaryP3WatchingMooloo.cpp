#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k, prev = 0, ans = 0;

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        long long x;

        cin >> x;

        if (x - prev > k || i == 0) {
            ans += k + 1;
        } else {
            ans += x - prev;
        }
        prev = x;
    }

    cout << ans;
}