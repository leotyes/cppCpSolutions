#include <bits/stdc++.h>
using namespace std;

vector<int> vp;

int parent(int x) {
    return x == vp[x] ? x : vp[x] = parent(vp[x]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, ans = 0;
    string s;

    cin >> n >> m >> k >> s;

    vp.resize(n + 1);
    for (int i = 0; i <= n; i++) vp[i] = i;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (s[a - 1] == s[b - 1]) {
            int pca = parent(a), pcb = parent(b);
            vp[pca] = pcb;
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        if (parent(a) == parent(b)) ans++;
    }

    cout << ans;
}