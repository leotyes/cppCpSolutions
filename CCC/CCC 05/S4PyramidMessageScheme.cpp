#include <bits/stdc++.h>
using namespace std;
// find the max depth probably
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l;

    cin >> l;

    while (l--) {
        int n, curd = 0, ans = -1;
        cin >> n;
        vector<string> vs(n);
        map<string, int> md;
        for (int i = 0; i < n; i++) {
            cin >> vs[i];
        }

        md[vs.back()] = 0;
        for (int i = 0; i < n - 1; i++) {
            if (md.find(vs[i]) != md.end()) {
                curd--;
            } else {
                curd++;
                md[vs[i]] = curd;
            }
        }

        for (auto x : md) {
            if (x.second > ans) ans = x.second;
        }

        cout << n * 10 - 2 * ans * 10 << "\n";
    }
}