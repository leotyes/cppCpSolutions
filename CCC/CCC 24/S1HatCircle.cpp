#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, c = 0;

    cin >> n;
    vector<int> table(n);

    for (int i = 0; i < n / 2; i++) {
        cin >> table[i];
    }

    for (int i = (n / 2); i < n; i++) {
        int q;

        cin >> q;

        if (table[i - (n / 2)] == q) {
            c += 2;
        }
    }

    cout << c;
}