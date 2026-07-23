#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> va(n), vb(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> vb[i];
    }
    vector<int> nva = va;
    for (int i = 0; i < n - 1; i++) {
        if ((nva[i] + nva[i + 1]) % 2 == vb[i]) continue;
        nva[i + 1] = (nva[i + 1] + 1) % 2;
        ans++;
    }
    int ans1 = 1;
    nva = va;
    nva[0] = (nva[0] + 1) % 2;
    for (int i = 0; i < n - 1; i++) {
        if ((nva[i] + nva[i + 1]) % 2 == vb[i]) continue;
        nva[i + 1] = (nva[i + 1] + 1) % 2;
        ans1++;
    }
    cout << min(ans, ans1);
}