#include <bits/stdc++.h>
using namespace std;

bool word(string &s, int &i);

bool aword(string &s, int &i) {
    if (i >= s.size()) return false;
    if (s[i] == 'A') {
        i++;
        return true;
    }

    if (s[i] == 'B') {
        i++;
        if (!word(s, i)) return false;
        if (i >= s.length() || s[i] != 'S') return false;
        i++;
        return true;
    }

    return false;
}

bool word(string &s, int &i) {
    if (!aword(s, i)) return false;
    if (i < s.size() && s[i] == 'N') {
        i++;
        return word(s, i);
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;

    while (true) {
        cin >> s;

        int i = 0;

        if (s == "X") {
            break;
        }

        if (word(s, i) && i == s.size()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}