#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;

    cin >> s;

    int h = count(s.begin(), s.end(), 'H'), v = count(s.begin(), s.end(), 'V');;

    if (h % 2 == 0 && v % 2 == 0) {
        cout << "1 2\n3 4";
    } else if (h % 2 == 1 && v % 2 == 1) {
        cout << "4 3\n2 1";
    } else if (h % 2 == 1 && v % 2 == 0) {
        cout << "3 4\n1 2";
    } else {
        cout << "2 1\n4 3";
    }
}