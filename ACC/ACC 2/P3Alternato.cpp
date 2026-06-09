#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vn;

bool isalt() {
    for (int i = 1; i < n - 1; i++) {
        if ((vn[i - 1] <= vn[i] && vn[i] <= vn[i + 1]) || (vn[i - 1] >= vn[i] && vn[i] >= vn[i + 1])) return false;
    }
    return true;
}

bool check(int x, int c) {
    vn[x] += c;
    if (isalt()) return true;
    vn[x] -= c;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vn.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
    }

    if (n == 2) {
        if (vn[0] == vn[1]) {
            cout << 1;
        } else {
            cout << 0;
        }
        return 0;
    }

    if (isalt()) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n - 1; i++) {
        if (vn[i] == vn[i + 1]) {
            if (check(i, 1) || check(i, -1) || check(i + 1, 1) || check(i + 1, -1)) {
                cout << 1;
                return 0;
            } else {
                cout << -1;
                return 0;
            }
        }
    }

    cout << -1;
}