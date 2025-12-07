#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int j, a, ans = 0;

    cin >> j >> a;

    vector<int> vs(j);
    vector<bool> vu(j, false);

    for (int i = 0; i < j; i++) {
        char c;

        cin >> c;

        switch (c) {
            case 'S':
                vs[i] = 0;
                break;
            case 'M':
                vs[i] = 1;
                break;
            case 'L':
                vs[i] = 2;
                break;
        }
    }

    for (int i = 0; i < a; i++) {
        char s;
        int si, n;

        cin >> s >> n;

        switch (s) {
            case 'S':
                si = 0;
                break;
            case 'M':
                si = 1;
                break;
            case 'L':
                si = 2;
                break;
        }

        if (vs[n - 1] >= si && !vu[n - 1]) {
            vu[n - 1] = true;
            ans++;
        }
    }

    cout << ans;
}