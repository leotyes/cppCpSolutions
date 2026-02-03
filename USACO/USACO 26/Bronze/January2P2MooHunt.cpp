// partials
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vdm;
vector<vector<int>> vm;
int n;
int smax = -1;
map<int, int> fans;

void dfs(int ci, int cs, int rs) {
    if (ci == n + 1) {
        smax = max(smax, cs);
        fans[cs]++;
        return;
    }
    if (cs + rs < smax) return;
    vector<vector<int>> vs;
    int tcs = cs, trs = rs;
    for (int i : vdm[ci]) {
        vs.push_back({i, vm[i][4], vm[i][6]});
        if (vm[i][6] == 1) continue;
        vm[i][4]--;
        if (vm[i][0] != ci) {
            vm[i][6] = 1;
            trs -= vm[i][3];
        } else if (vm[i][4] == 0) {
            tcs += vm[i][3];
            trs -= vm[i][3];
        }
    }
    dfs(ci + 1, tcs, trs);
    tcs = cs;
    trs = rs;
    for (auto x : vs) {
        vm[x[0]][4] = x[1];
        vm[x[0]][6] = x[2];
    }
    for (int i : vdm[ci]) {
        if (vm[i][6] == 1) continue;
        vm[i][4]--;
        if (vm[i][0] != ci) {
            if (vm[i][4] == 0) {
                tcs += vm[i][3];
                trs -= vm[i][3];
            }
        } else {
            vm[i][6] = 1;
            trs -= vm[i][3];
        }
    }
    dfs(ci + 1, tcs, trs);
    for (auto x : vs) {
        vm[x[0]][4] = x[1];
        vm[x[0]][6] = x[2];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k;

    cin >> n >> k;

    vdm.resize(n + 1, vector<int>());
    map<tuple<int, int, int>, int> mt;

    for (int i = 0; i < k; i++) {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        mt[make_tuple(xi, yi ,zi)]++;
    }

    int tc = 0, irs = 0;

    for (auto [p, f] : mt) {
        auto [xi, yi, zi] = p;
        vdm[xi].push_back(tc);
        vdm[yi].push_back(tc);
        vdm[zi].push_back(tc);
        // unknowns, good, impossible
        vm.push_back({xi, yi, zi, f, 3, 0, 0});
        irs += f;
        tc++;
    }
    dfs(1, 0, irs);
    cout << fans.rbegin()->first << " " << fans.rbegin()->second;
}