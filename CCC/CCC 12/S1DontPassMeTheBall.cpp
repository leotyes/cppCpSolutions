#include <bits/stdc++.h>
using namespace std;

long long ans = 0;

void pass(int c, int cn) {
    if (cn == 4) {
        ans++;
        return;
    }
    for (int i = 4 - cn; i < c; i++) {
        pass(i, cn + 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int j;

    cin >> j;

    if (j < 4) {
        cout << 0;
        return 0;
    }

    pass(j, 1);

    cout << ans;
}