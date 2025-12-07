#include <bits/stdc++.h>
using namespace std;

void tower(int n, char cur, char help, char dest) {
    if (n == 1) {
        cout << cur << dest << "\n";
    } else {
        tower(n - 1, cur, dest, help);
        cout << cur << dest << "\n";
        tower(n - 1, help, cur, dest);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    tower(n, 'A', 'B', 'C');
}