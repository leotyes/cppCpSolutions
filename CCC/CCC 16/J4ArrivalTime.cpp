#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n, h = "", m = "";

    cin >> n;

    h += n[0];
    h += n[1];
    m += n[3];
    m += n[4];

    int tr = 60 * stoi(h) + stoi(m), ans = tr, d = 0;

    while (d < 240) {
        if ((420 <= ans && ans < 600) || (900 <= ans && ans < 1140)) {
            d++;
        } else {
            d += 2;
        }
        ans++;
    }

    ans = ans % 1440;

    if (ans / 60 < 10) {
        cout << '0' << ans / 60;
    } else {
        cout << ans / 60;
    }
    cout << ':' << ans % 60;
    if (ans % 60 < 10) {
        cout << '0';
    }
}