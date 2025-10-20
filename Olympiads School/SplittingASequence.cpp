#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long lo = *max_element(a.begin(), a.end()), hi = accumulate(a.begin(), a.end(), 0LL), ans;

    while (lo <= hi) {
        long long mid = (lo + hi) / 2, currsum = 0, p = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] + currsum <= mid) {
                currsum += a[i];
            } else {
                p++;
                currsum = a[i];
            }
        }
        if (p <= m) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans;
}