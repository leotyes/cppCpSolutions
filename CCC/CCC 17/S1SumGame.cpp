#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    bool found = false;
    cin >> n;

    vector<int> psaa(n), psab(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            psaa[i] = x;
        } else {
            psaa[i] = psaa[i - 1] + x;
        }
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (i == 0) {
            psab[i] = x;
        } else {
            psab[i] = psab[i - 1] + x;
        }
    }

    for (auto it = psaa.rbegin(); it != psaa.rend(); it++) {
        if (*it == psab[n - (it - psaa.rbegin()) - 1]) {
            found = true;
            cout << n - (it - psaa.rbegin());
            break;
        }
    }

    if (!found) {
        cout << 0;
    }
}