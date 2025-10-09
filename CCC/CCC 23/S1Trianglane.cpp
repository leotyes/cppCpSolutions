#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int c, ans = 0;
    queue<int> q1;

    cin >> c;

    vector<int> v1(c, 0), v2(c, 0);

    for (int i = 0; i < c; i++) {
        cin >> v1[i];
    }

    for (int i = 0; i < c; i++) {
        cin >> v2[i];
    }

    for (int i = 0; i < c; i++) {
        if (v1[i] == 1) {
            if (i % 2 == 0) {
                if (i != 0) {
                    if (v1[i - 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (i != c - 1) {
                    if (v1[i + 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (v2[i] == 0) ans++;
            } else {
                if (i != 0) {
                    if (v1[i - 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (i != c - 1) {
                    if (v1[i + 1] == 0) ans++;
                } else {
                    ans++;
                }
                ans++;
            }
        }
    }

    for (int i = 0; i < c; i++) {
        if (v2[i] == 1) {
            if (i % 2 == 0) {
                if (i != 0) {
                    if (v2[i - 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (i != c - 1) {
                    if (v2[i + 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (v1[i] == 0) ans++;
            } else {
                if (i != 0) {
                    if (v2[i - 1] == 0) ans++;
                } else {
                    ans++;
                }
                if (i != c - 1) {
                    if (v2[i + 1] == 0) ans++;
                } else {
                    ans++;
                }
                ans++;
            }
        }
    }

    cout << ans;
}