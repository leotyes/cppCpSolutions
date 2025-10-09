#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;

    cin >> n >> m >> q;

    vector<int> diff((n * m) + 2, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int low = i * j, high = (n * m) - ((n - i + 1) * (m - j + 1)) + 1;

            diff[low]++;
            diff[high + 1]--;
        }
    }

    vector<int> psa((n * m) + 1, 0);

    for (int i = 1; i <= (n * m); i++) {
        psa[i] = psa[i - 1] + diff[i];
    }

    for (int i = 0; i < q; ++i) {
        int x;
        cin >> x;
        cout << psa[x] << "\n";
    }
}