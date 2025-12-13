#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        int c = 0;
        bool w = false, e = false, cann = false;

        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            if (j < s.length() - 2 && s[j] == 'g' && s[j + 1] == 'r' && s[j + 2] == 'e') {
                w = true;
                j += 2;
            } else if (w) {
                if (s[j] == 'n') {
                    c++;
                    w = false;
                } else if (s[j] != 'e') {
                    w = false;
                }
            }
        }

        cout << c << "\n";
    }
}