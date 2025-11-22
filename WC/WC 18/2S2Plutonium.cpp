#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, ansmin = 0, ansmax = 0, prevv = 1, previ = 1;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x;

        cin >> x;

        int exp = i - previ + prevv;

        if (x > exp) {
            cout << -1;
            return 0;
        }

        if (x != 0) {
            if (i != 1) {
                if (x < exp) {
                    if (i - previ < x) {
                        cout << -1;
                        return 0;
                    }
                    ansmin++;
                    ansmax += i - previ - x + 1;
                }
                previ = i;
                prevv = x;
            }
        }
    }

    if (previ != n) {
        ansmax += n - previ;
    }

    cout << ansmin << " " << ansmax;
}