#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    vector<int> vx(n + 1, 0);
    for (int i = 0; i < n; i++) {
        vx[i + 1] = (s[i] == 'x' ? 1 : 0) + vx[i];
    }
    int r = 1;
    for (int l = 1; l <= n; l++) {
        r = max(r, l);

        while (r < n && vx[r] < l) {
            r++;
        }
        cout << r << '\n';
    }
}