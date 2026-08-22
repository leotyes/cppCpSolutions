#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> psa(s.size() + 1);
    psa[0] = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') {
            psa[i + 1] = psa[i] + 1;
        } else {
            psa[i + 1] = psa[i];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << psa[r + 1] - psa[l] << '\n';
    }
}