#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, cc = 0;
    bool m = false;
    long long int x;
    string s;
    cin >> n >> x >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'R' || s[i] == 'L') {
            if (m) {
                cc++;
            } else if (x > pow(10, 18) / 2) {
                m = true;
                cc++;
            } else {
                if (s[i] == 'L') {
                    x *= 2;
                } else {
                    x = (2 * x) + 1;
                }
            }
        } else {
            if (m) {
                cc--;
                if (cc == 0) {
                    m = false;
                }
            } else {
                x /= 2;
            }
        }
    }
    cout << x;
}