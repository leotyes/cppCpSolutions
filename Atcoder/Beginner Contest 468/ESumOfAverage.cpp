#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m = 998244353;
    cin >> n;
    vector<int> vn(n), vi(n + 1, 1);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 2; i <= n; i++) {
        vi[i] = m - m / i * vi[m % i] % m;
    }
}