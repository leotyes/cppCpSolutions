#include <bits/stdc++.h>
using namespace std;
"the sun will rise again, and we will try again";
int m = -1;
vector<tuple<int, int, int, int, int>> vv;   
void take(array<array<bool, 1000>, 1000>& ah, vector<int>& ct, int cs) {
    for (int& i : ct ) {
        int s, f, b, e, v;
        tie(s, f, b, e, v) = vv[i];
        for (int j = s; j <= f; ++j) {
            if (!all_of(ah[j].begin() + b, ah[j].begin() + e + 1, [](bool x) { return !x; })) {
                return;
            }
        }
        for (int j = s; j <= f; ++j) {
            fill(ah[j].begin() + b, ah[j].begin() + e + 1, true);
        }
        ct.erase(ct.begin());
        m = max(m, cs + v);
        take(ah, ct);
        for (int j = s; j <= f; ++j) {
            fill(ah[j].begin() + b, ah[j].begin() + e + 1, false);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, rs, re;
    bool bk = false;
    vector<int> ct;
    cin >> n >> m;
    array<array<bool, 1001>, 1001> ah;
    for (int i = 0; i < n; ++i) {
        int s, f, b, e, m, v;
        cin >> s >> f >> b >> e >> m >> v;
        if (m == 1) {
            for (int j = s; j <= f; ++j) {
                if (all_of(ah[j].begin() + b, ah[j].begin() + e + 1, [](bool x) { return !x; })) {
                    fill(ah[j].begin() + b, ah[j].begin() + e + 1, true);
                } else {
                    cout << "-1";
                    return 0;
                }
            }
        } else {
            vv.emplace_back(s, f, b, e, v);
            ct.push_back(v.size() - 1);
        }
    }
    take(ah, ct);
}