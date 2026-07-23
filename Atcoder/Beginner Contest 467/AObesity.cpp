#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h, w;
    cin >> h >> w;

    if (h * h * 25 <= w * 100 * 100) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}