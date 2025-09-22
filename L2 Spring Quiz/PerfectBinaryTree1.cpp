#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    long long int x, y;
    cin >> x >> y;
    if (x == 1) {
        cout << "YES";
        return 0;
    }
    while (y != 1) {
        if (y == x) {
            cout << "YES";
            return 0;
        }
        y /= 2;
    }
    cout << "NO";
    return 0;
}