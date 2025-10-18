#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long p, y, t;

    cin >> p >> y >> t;

    long long lo = 1, hi = t, ans;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2, start = mid;
        for (int i = 0; i < y; i++) {
            start += start * p / 100;
            if (i != y - 1) {
                start += mid;
            }
            if (start >= t) {
                ans = mid;
                hi = mid - 1;
                break;
            }
        }
        if (start < t) {
            lo = mid + 1;
        }
    }

    cout << ans;
}