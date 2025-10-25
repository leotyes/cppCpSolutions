#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    long long lo = 1, hi = 1e18, ans;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2, wmoos = mid - (mid / 3) - (mid / 5) + (mid / 15);
        if (wmoos < n) {
            lo = mid + 1;
        } else {
            ans = mid;
            hi = mid - 1;
        }
    }

    cout << ans;
}