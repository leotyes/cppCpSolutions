#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        int c = 0;

        cin >> s;

        if (count(s.begin(), s.end(), 'a') == 0) {
            c++;
        }
        if (count(s.begin(), s.end(), 'b') == 0) {
            c++;
        }
        if (count(s.begin(), s.end(), 'c') == 0) {
            c++;
        }

        if (c == 2) {
            cout << s.length() << "\n";
            continue;
        }

        if (count(s.begin(), s.end(), 'a') % 2 == count(s.begin(), s.end(), 'b') % 2 && count(s.begin(), s.end(), 'b') % 2 == count(s.begin(), s.end(), 'c') % 2) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}