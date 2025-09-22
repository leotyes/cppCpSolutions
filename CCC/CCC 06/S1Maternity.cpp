#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    bool iv = false;
    array<array<string, 2>, 5> vs;
    cin >> a >> b;
    for (int i = 0; i < 10; i += 2) {
        vs[i / 2][0] = a.substr(0, 2);
        a.erase(a.begin(), a.begin() + 2);
    }
    for (int i = 0; i < 10; i += 2) {
        vs[i / 2][1] = b.substr(0, 2);
        b.erase(b.begin(), b.begin() + 2);
    }
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        iv = false;
        string s;
        cin >> s;
        for (int j = 0; j < 5; ++j) {
            if (isupper(s[j])) {
                if (vs[j][0] == vs[j][1] && vs[j][0] == string(2, tolower(s[j]))) {
                    cout << "Not their baby!" << '\n';
                    iv = true;
                    break;
                }
            } else {
                if (vs[j][0] == string(2, toupper(s[j])) || vs[j][1] == string(2, toupper(s[j]))) {
                    cout << "Not their baby!" << '\n';
                    iv = true;
                    break;
                }
            }
        }
        if (!iv) {
            cout << "Possible baby." << '\n';
        }
    }
}