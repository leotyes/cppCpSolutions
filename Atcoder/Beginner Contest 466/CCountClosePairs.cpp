#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;
    int next = 1;
    for (int i = 1; i <= n - 1; i++) {
        int far = max(i, next), j = max(i + 1, next + 1);
        for (; j <= n; j++) {
            cout << "? " << i << ' ' << j << endl;
            string s;
            cin >> s;
            if (s == "Yes") {
                far = j;
            } else {
                break;
            }
        }
        ans += far - i;
        next = max(next, far);
    }
    cout << "! " << ans << endl;
}