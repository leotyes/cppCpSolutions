#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string prev;

    while (true) {
        string s;

        cin >> s;

        if (s == "99999") break;

        if (s[0] == '0' && s[1] == '0') {
            cout << prev << s.substr(2, 3);
        } else if (((int)s[0] + (int)s[1]) % 2 == 0) {
            cout << "right " << s.substr(2, 3);
            prev = "right ";
        } else {
            cout << "left " << s.substr(2, 3);
            prev = "left ";
        }
        cout << "\n";
    }
}