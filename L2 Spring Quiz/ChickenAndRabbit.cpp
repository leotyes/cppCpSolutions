#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    for (int i = 0; i <= x; ++i) {
        int yn = 2 * (x - i) + 4 * i;
        if (yn == y) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}