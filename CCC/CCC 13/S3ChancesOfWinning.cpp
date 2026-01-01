#include <bits/stdc++.h>
using namespace std;

int ans = 0, t;

void play(set<pair<int, int>> rg, vector<int> cp) {
    if (rg.size() == 0) {
        if (*max_element(cp.begin(), cp.end()) == cp[t] && count(cp.begin(), cp.end(), *max_element(cp.begin(), cp.end())) == 1) {
            ans++;
        }
    } else {
        set<pair<int, int>> rrg = rg;
        vector<int> ccp = cp;
        pair<int, int> fp = *rg.begin();
        ccp[fp.first] += 3;
        rrg.erase(fp);
        play(rrg, ccp);
        ccp = cp;
        ccp[fp.second] += 3;
        play(rrg, ccp);
        ccp = cp;
        ccp[fp.first] += 1;
        ccp[fp.second] += 1;
        play(rrg, ccp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int g;

    cin >> t >> g;
    t--;

    set<pair<int, int>> sg = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
    vector<int> vs = {0, 0, 0, 0};

    for (int i = 0; i < g; i++) {
        int a, b, sa, sb;

        cin >> a >> b >> sa >> sb;
        a--;
        b--;

        if (sa > sb) {
            vs[a] += 3;
        } else if (sb > sa) {
            vs[b] += 3;
        } else {
            vs[a]++;
            vs[b]++;
        }
        if (a > b) swap(a, b);
        sg.erase({a, b});
    }

    play(sg, vs);
    cout << ans;
}