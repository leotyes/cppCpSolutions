#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mmax;
    while (n--) {
        int c, s;
        cin >> c >> s;
        mmax[c] = max(mmax[c], s);
    }
    for (int i = 1; i <= m; i++) {
        if (mmax[i] == 0) {
            cout << "-1 ";
            continue;
        }
        cout << mmax[i] << ' ';
    }
}