#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;
    int ans = 0;

    for (int i = 1; i <= 100; i++) {
        if (i > a.length() || i > b.length()) break;
        string tempa = a.substr(a.length() - i), tempb = b.substr(0, i);
        if (tempa == tempb) ans = i;
    }

    for (int i = 1; i <= 100; i++) {
        if (i > a.length() || i > b.length()) break;
        string tempa = a.substr(0, i), tempb = b.substr(b.length() - i);
        if (tempa == tempb) ans = max(ans, i);
    }

    cout << ans;
}