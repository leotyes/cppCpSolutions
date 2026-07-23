#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    bool ans = true;
    cin >> n;
    vector<int> vn(n);
    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        if (vn[i] >= 0) {
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No");
}