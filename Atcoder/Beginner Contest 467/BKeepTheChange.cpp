#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x = 10000, y = 10000;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (s == "keep") {
            x -= b;
        } else {
            x -= a;
        }
        y -= a;
    }
    cout << y - x;
}