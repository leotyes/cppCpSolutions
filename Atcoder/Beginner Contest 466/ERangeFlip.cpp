#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> vdiff(n, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vdiff[i] = b - a;
    }
}