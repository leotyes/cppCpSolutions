#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;

    getline(cin, s);

    vector<vector<int>> psm(26, vector<int>(s.size() + 1, 0));

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            psm[j][i + 1] = psm[j][i];
        }
        if (s[i] != ' ') {
            psm[s[i] - 'a'][i + 1]++;
        }
    }

    int q;

    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r;
        char c;

        cin >> l >> r >> c;

        cout << psm[c - 'a'][r] - psm[c - 'a'][l - 1] << "\n";
    }
}