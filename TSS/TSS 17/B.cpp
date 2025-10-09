#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    vector<long long> d;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        d.push_back(pow(x, 2) + pow(y, 2));
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < q; i++) {
        int r;
        cin >> r;

        cout << upper_bound(d.begin(), d.end(), pow(r, 2)) - d.begin() << "\n";
    }
}