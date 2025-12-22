#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;

    cin >> n;

    vector<long long> vn(n + 1), vd(n + 1);
    vn[0] = vd[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> vn[i];
        vd[i] = vn[i] - vn[1];
    }

    for (int i = 2; i <= n; i++) {
        ans += llabs(vd[i]);
        long long og = vd[i];
        for (int j = i; j <= n; j += i) {
            vd[j] -= og;
        }
    }

    cout << ans;
}