#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tot = 0;
    cin >> n;
    vector<tuple<int, int, int>> ve;
    set<int> ond;
    vector<int> vsin(n, 0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ve.emplace_back(a, i, 1);
        ve.emplace_back(b, i, 0);
    }
    sort(ve.begin(), ve.end());
    int pi = 0;
    for (auto [i, l, b] : ve) {
        if (ond.size() > 0) {
            if (ond.size() == 1) {
                vsin[*ond.begin()] += i - pi;
            }
            tot += i - pi;
        }
        if (b == 1) {
            ond.insert(l);
        } else {
            ond.erase(l);
        }
        pi = i;
    }
    cout << tot - *min_element(vsin.begin(), vsin.end()) << '\n';
}