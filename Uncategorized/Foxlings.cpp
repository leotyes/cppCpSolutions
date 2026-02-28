#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int parent(int x) {
    int p = x;
    while (mp[p] != p) p = mp[p];
    while (x != p) {
        int np = mp[x];
        mp[x] = p;
        x = np;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (mp.find(a) == mp.end()) mp[a] = a;
        if (mp.find(b) == mp.end()) mp[b] = b;
        int pca = parent(a), pcb = parent(b);
        mp[pca] = pcb;
    }
    int ans = 0;
    for (auto [no, p] : mp) if (no == p) ans++;
    cout << ans + n - mp.size();
}