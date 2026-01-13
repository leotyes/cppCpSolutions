#include <bits/stdc++.h>
using namespace std;

vector<string> vg;
int ans = 0, r, c;
map<char, int> m{{'S', 1}, {'M', 5}, {'L', 10}};

void dfs(int curr, int curc) {
    if (curr < r - 1 && vg[curr + 1][curc] != '*') {
        ans += m[vg[curr + 1][curc]];
        vg[curr + 1][curc] = '*';
        dfs(curr + 1, curc);
    }
    if (curr > 0 && vg[curr - 1][curc] != '*') {
        ans += m[vg[curr - 1][curc]];
        vg[curr - 1][curc] = '*';
        dfs(curr - 1, curc);
    }
    if (curc < c - 1 && vg[curr][curc + 1] != '*') {
        ans += m[vg[curr][curc + 1]];
        vg[curr][curc + 1] = '*';
        dfs(curr, curc + 1);
    }
    if (curc > 0 && vg[curr][curc - 1] != '*') {
        ans += m[vg[curr][curc - 1]];
        vg[curr][curc - 1] = '*';
        dfs(curr, curc - 1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int curr, curc;

    cin >> r >> c;

    vg.resize(r);

    for (int i = 0; i < r; i++) {
        cin >> vg[i];
    }

    cin >> curr >> curc;

    ans += m[vg[curr][curc]];
    vg[curr][curc] = '*';
    dfs(curr, curc);

    cout << ans;
}