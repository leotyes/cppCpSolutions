#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    double ans = 1e9;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 1; i < n - 1; i++) {
        ans = min(ans, ((v[i + 1] - v[i]) / 2.0 + (v[i] - v[i - 1]) / 2.0));
    }

    cout << fixed << setprecision(1) << ans;
}