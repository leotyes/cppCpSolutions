#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, c = 0;

    cin >> n;

    vector<long long> a(n), s(n);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        a[i] = x;
        s[i] = x;
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) {
            c++;
            if (c > 2) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}