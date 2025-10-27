#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<vector<int>> cols(n, vector<int>(n)), rows(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ni;

            cin >> ni;

            rows[i][j] = ni;
            cols[j][i] = ni;
        }
    }

    if (rows[0][0] < rows[0][1] && rows[0][0] < rows[1][0]) {
        for (auto row : rows) {
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
    } else if (rows[0][0] > rows[0][1] && rows[0][0] < rows[1][0]) {
        for (int i = n - 1; i >= 0; i--) {
            copy(cols[i].begin(), cols[i].end(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
    } else if (rows[0][0] < rows[0][1] && rows[0][0] > rows[1][0]) {
        for (auto col : cols) {
            copy(col.rbegin(), col.rend(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
    } else {
        for (int i = n - 1; i >= 0; i--) {
            copy(rows[i].rbegin(), rows[i].rend(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
    }
}