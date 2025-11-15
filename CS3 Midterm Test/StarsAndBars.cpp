#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<long long> a(n), ans(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 2; i += 2) {
        ans[0] += a[i] * 2;
        ans[0] -= a[i + 1] * 2;
    }

    ans[0] += a[n - 1] * 2;
    ans[0] /= 2;

    for (int i = 1; i < n; i++) {
        ans[i] = a[i - 1] * 2 - ans[i - 1];
    }

    for (long long x : ans) {
        cout << x << " ";
    }
}