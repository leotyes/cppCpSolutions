#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, k;

    cin >> t >> k;

    while (t--) {
        if (k == 0) {
            cout << "YES\n";
        } else {
            int n, f = 0;
            string s;
            cin >> n >> s;
            vector<char> vans(n);
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == 'O' && f % 2 == 0) {
                    f++;
                    vans[i] = 'O';
                } else if (s[i] == 'O' && f % 2 == 1) {
                    vans[i] = 'M';
                } else if (s[i] == 'M' && f % 2 == 1) {
                    f++;
                    vans[i] = 'O';
                } else {
                    vans[i] = 'M';
                }
            }
            cout << "YES\n";
            for (char x : vans) {
                cout << x;
            }
            cout << "\n";
        }
    }
}
Moo Hunt
Purchasing Milk