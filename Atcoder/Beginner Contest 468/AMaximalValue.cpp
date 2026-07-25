#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }
    for (int i = 0; i < n - 2; i++) {
        if (vn[i + 1] > vn[i] && vn[i + 1] > vn[i + 2]) ans++;
    }
    cout << ans;
}