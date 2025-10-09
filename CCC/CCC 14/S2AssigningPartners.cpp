#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n % 2 != 0) {
        cout << "bad";
        return 0;
    }

    vector<string> l1(n);
    vector<string> l2(n);
    set<set<string>> partners;

    for (int i = 0; i < n; i++) {
        cin >> l1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> l2[i];
    }

    for (int i = 0; i < n; i++) {
        set<string> pair;
        pair.insert(l1[i]);
        pair.insert(l2[i]);
        if (pair.size() != 2) {
            cout << "bad";
            return 0;
        }
        partners.insert(pair);
    }

    if (partners.size() == n / 2) {
        cout << "good";
    }
}