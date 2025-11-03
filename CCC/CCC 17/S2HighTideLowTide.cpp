#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> vt(n);

    for (int i = 0; i < n; i++) {
        cin >> vt[i];
    }

    sort(vt.begin(), vt.end());

    if (n % 2 == 0) {
        for (auto it = vt.rbegin(); it != vt.rbegin() + (n / 2); it++) {
            cout << vt[(n / 2) - (it - vt.rbegin()) - 1] << " " << vt[(n / 2) + (it - vt.rbegin())] << " ";
        }
    } else {
        for (auto it = vt.rbegin(); it != vt.rbegin() + (n / 2); it++) {
            cout << vt[(n / 2) - (it - vt.rbegin())] << " " << vt[(n / 2) + (it - vt.rbegin()) + 1] << " ";
        }
        cout << vt[0];
    }
}