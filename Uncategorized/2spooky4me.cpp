#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l, st, ans = 0;

    cin >> n >> l >> st;

    map<int, int> dif;

    for (int i = 0; i < n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        dif[a - 1] += s;
        dif[b] -= s;
    }

    int cur = 0, previn = 0, prevv = 0;

    for (auto [in, v] : dif) {
        cur += v;
        if (prevv < st) {
            ans += in - previn;
        }
        previn = in;
        prevv += v;
    }

    if (prevv < st) {
        ans += l - previn;
    }

    cout << ans;
}