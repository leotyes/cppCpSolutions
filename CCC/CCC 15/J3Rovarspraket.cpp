#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    set<char> sv{'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        char mc = ' ';
        int md = 99999;

        if (find(sv.begin(), sv.end(), s[i]) == sv.end()) {
            for (char x : sv) {
                if (abs(x - s[i]) < md) {
                    mc = x;
                    md = abs(x - s[i]);
                }
            }
            cout << mc;
            if (s[i] == 'z') {
                cout << 'z';
            } else if (find(sv.begin(), sv.end(), s[i] + 1) != sv.end()) {
                cout << (char)(s[i] + 2);
            } else {
                cout << (char)(s[i] + 1);
            }
        }
    }
}