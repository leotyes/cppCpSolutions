#include <bits/stdc++.h>
using namespace std;

long long n;
vector<int> fib{0, 1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    if (n == 0) {
        cout << 0;
        return 0;
    } else if (n == 1) {
        cout << 1;
        return 1;
    }

    for (int i = 2; i <= n; i++) {
        int nf = (fib[0] + fib[1]) % 1000000007;
        fib[0] = fib[1];
        fib[1] = nf;
    }

    cout << fib[1];
}