#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n;
    unordered_map<int, int> md, ma;
    unordered_map<long long, int> mo;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        md[a]++;
        ma[b]++;
        mo[a * 3LL * 1000000 + b]++;
    }
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << md[x] + ma[y] - mo[x * 3LL * 1000000 + y] << "\n";
    }
}