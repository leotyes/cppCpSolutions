#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n, ans = -1;

    cin >> n;

    if (n == 1) {
        cout << 2;
        return 0;
    }

    while (ans == -1) {
        bool b = false;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0LL) {
                b = true;
                break;
            }
        }
        if (!b) {
            ans = n;
        }
        n++;
    }

    cout << ans;
}