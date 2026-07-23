#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = INT_MAX;
    cin >> n;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    sort(vn.begin(), vn.end());
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, abs(vn[i] - vn[i + 1]));
    }
    cout << ans;
}