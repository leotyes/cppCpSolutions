#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long a, b, k, t;

    cin >> a >> b >> k >> t;

    long long dif = llabs(a - b), bh = dif / k, sec = -1;

    if ((dif % k) != 0) {
        sec = bh + 1;
    }

    long long minans = min(bh + (dif % k), sec + (sec * k) - dif);

    if (t == 1) {
        if (sec == -1) {
            cout << bh;
        } else {
            cout << minans;
        }
    } else {
        if (sec == -1) {
            if (k == 2) {
                if (dif == 0) {
                    cout << 2;
                } else {
                    cout << bh + 1;
                }
            } else {
                cout << bh + 2;
            }
        } else {
            if (bh + (dif % k) == (sec + (sec * k) - dif)) {
                cout << bh + (dif % k) + 2;
            } else {
                long long maxans = max(bh + (dif % k), sec + (sec * k) - dif);
                cout << min(maxans, minans + 2);
            }
        }
    }
}