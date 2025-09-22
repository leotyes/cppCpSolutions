#include <bits/stdc++.h>
using namespace std;

int KnittingScarves() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;

    cin >> n >> q;

    vector<int> next(n + 1, -1), prev(n + 1, -1);
    iota(next.begin(), next.end(), 1);
    iota(prev.begin() + 1, prev.end(), 0);

    for (int i = 0; i < q; i++) {
        int l, r, k;

        cin >> l >> r >> k;

        prev[next[r]] = prev[l];
        next[prev[l]] = next[r];
        prev[l] = k;
        next[r] = next[k];
        prev[next[k]] = r;
        next[k] = l;
        cout << "\n";
    }

    int pre;
    cout << next[0] << " ";
    pre = next[0];
    for (int j = 1; j < n; j++) {
        cout << next[pre] << " ";
        pre = next[pre];
    }
}