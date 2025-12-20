#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
vector<set<int>> vs;

void pizza(int ci, set<int> exclude) {
    for (int i = ci + 1; i < n; i++) {
        if (exclude.find(i) == exclude.end()) {
            ans++;
            set<int> tempex = exclude;
            for (int x : vs[i]) {
                tempex.insert(x);
            }
            pizza(i, tempex);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    ans = n + 1;

    vs.assign(n, {});

    for (int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        vs[a - 1].insert(b - 1);
        vs[b - 1].insert(a - 1);
    }

    for (int i = 0; i < n; i++) {
        pizza(i, vs[i]);
    }

    cout << ans;
}