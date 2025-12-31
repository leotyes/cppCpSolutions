#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, x, cur, end;

    cin >> n >> k >> x;

    for (int i = 0; i < n - 1; i++) {
        cout << k - 1 << " ";
    }

    cur = end = k - 1;

    for (int i = 0; i < n - 2; i++) {
        cur = (cur * 2) % k;
        end = (cur + end) % k;
    }

    cout << (x - end + k) % k;
}