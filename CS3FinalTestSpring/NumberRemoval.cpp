#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, curp, count = 1;
    int k;

    cin >> n >> k;

    curp = n;

    while (true) {
        if (curp % k == 0) {
            cout << count;
            return 0;
        } else if (curp < k) {
            cout << 0;
            return 0;
        } else {
            curp -= curp / k;
        }
        count++;
    }
}