#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int w, n, curw = 0;

    cin >> w >> n;

    vector<int> vw(n);

    for (int i = 0; i < n; i++) {
        cin >> vw[i];
    }

    for (int i = 0; i <= 3 && i < n; i++) {
        curw += vw[i];
        if (curw > w) {
            cout << i;
            return 0;
        }
        if (i == n - 1) {
            cout << n;
            return 0;
        }
    }

    for (int i = 4; i < n; i++) {
        curw -= vw[i - 4];
        curw += vw[i];
        if (curw > w) {
            cout << i;
            return 0;
        }
    }

    cout << n;
}