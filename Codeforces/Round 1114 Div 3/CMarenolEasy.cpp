#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, ac = 0, bc = 0;
        string a, b;
        cin >> n >> a >> b;
        if (count(a.begin(), a.end(), '1') != count(b.begin(), b.end(), '1')) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == '1' && i % 2 == 0) ac += 1;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == '1' && i % 2 == 0) bc += 1;
        }
        if (ac == bc) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}