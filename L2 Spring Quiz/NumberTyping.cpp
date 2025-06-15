#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n;
    int z = 0;
    cin >> n;

    for (int i = 0; i < n.size(); ++i) {
        if (n[i] == '0') {
            if (i != n.size() - 1 && n[i + 1] == '0') {
                i++;
                z++;
            }
        }
    }
    cout << n.size() - z;
}