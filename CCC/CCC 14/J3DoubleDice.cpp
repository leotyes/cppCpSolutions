#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a = 100, b = 100;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int an, bn;

        cin >> an >> bn;

        if (an == bn) continue;
        if (an > bn) {
            b -= an;
        } else {
            a -= bn;
        }
    }

    cout << a << "\n" << b;
}