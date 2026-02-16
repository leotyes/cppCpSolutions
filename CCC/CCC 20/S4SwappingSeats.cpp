#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, sa;

    cin >> s;

    sa = s + s;
    vector<int> apsa(sa.length(), 0), bpsa(sa.length(), 0), cpsa(sa.length(), 0);

    int as = count(s.begin(), s.end(), 'A'), bs = count(s.begin(), s.end(), 'B'), cs = count(s.begin(), s.end(), 'C');

    if (sa[0] == 'A') {
        apsa[0] = 1;
    } else if (sa[0] == 'B') {
        bpsa[0] = 1;
    } else {
        cpsa[0] = 1;
    }

    for (int i = 1; i < sa.length(); i++) {
        char c = sa[i];
        apsa[i] = apsa[i - 1];
        bpsa[i] = bpsa[i - 1];
        cpsa[i] = cpsa[i - 1];
        if (c == 'A') {
            apsa[i] = apsa[i - 1] + 1;
        } else if (c == 'B') {
            bpsa[i] = bpsa[i - 1] + 1;
        } else {
            cpsa[i] = cpsa[i - 1] + 1;
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i < sa.length() - (as + bs); i++) {
        int asina = apsa[i + as - 1] - (i == 0 ? 0 : apsa[i - 1]), bsina = bpsa[i + as - 1] - (i == 0 ? 0 : bpsa[i - 1]), bsinb = bpsa[i + as + bs - 1] - bpsa[i + as - 1], asinb = apsa[i + as + bs - 1] - apsa[i + as - 1];
        ans = min(as - asina + bs - bsinb - min(bsina, asinb), ans);
    }

    for (int i = 0; i < sa.length() - (as + cs); i++) {
        int asina = apsa[i + as - 1] - (i == 0 ? 0 : apsa[i - 1]), csina = cpsa[i + as - 1] - (i == 0 ? 0 : cpsa[i - 1]), csinc = cpsa[i + as + cs - 1] - cpsa[i + as - 1], asinc = apsa[i + as + cs - 1] - apsa[i + as - 1];
        ans = min(as - asina + cs - csinc - min(csina, asinc), ans);
    }

    cout << ans;
}