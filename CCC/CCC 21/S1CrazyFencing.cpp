#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long ans = 0;
    cin >> n;

    vector<int> h(n + 1), w(n);

    for (int i = 0; i <= n; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        ans += (h[i] + h[i + 1]) * w[i];
    }

    if (ans % 2 == 0) {
        cout << ans / 2;
    } else {
        cout << ans / 2 << ".5";
    }
}