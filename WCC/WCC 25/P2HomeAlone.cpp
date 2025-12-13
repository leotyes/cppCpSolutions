#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int p = 0;
    bool b = false;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') {
            b = true;
            break;
        }
        switch (s[i]) {
            case ('S'):
                p += 10;
                break;
            case ('M'):
                p += 100;
                break;
            case ('L'):
                p += 1000;
                break;
        }
    }
    if (b) {
        cout << 0;
    } else {
        cout << p;
    }
}