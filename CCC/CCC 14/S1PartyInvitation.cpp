#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, m;

    cin >> k >> m;

    vector<int> vn, vnn;

    for (int i = 1; i <= k; i++) {
        vn.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        int ri;

        cin >> ri;

        for (int j = 0; j < vn.size(); j++) {
            if ((j + 1) % ri != 0) {
                vnn.push_back(vn[j]);
            }
        }
        vn = vnn;
        vnn.clear();
    }

    for (int x : vn) {
        cout << x << "\n";
    }
}