#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, miss = 0;

    cin >> n;

    vector<int> v(n);
    map<int, int> m;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }

    for (int i = 0; i <= n; i++) {
        cout << max(miss, m[i]) << "\n";
        if (m[i] == 0) {
            miss++;
        }
    }
}