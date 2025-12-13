#include <bits/stdc++.h>
using namespace std;

int n, m, ans = INT_MAX, destx, desty;
vector<vector<char>> grid;
set<pair<int, int>> blizzard;
vector<pair<int, int>> dirs{make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};

void dfs(int t, pair<int, int> cur) {
    set<pair<int, int>> addedbliz;
    for (auto i = blizzard.begin(); i != blizzard.end(); i++) {
        for (auto p : dirs) {
            addedbliz.insert(make_pair(i->first + p.first, i->second + p.second));
            blizzard.insert(make_pair(i->first + p.first, i->second + p.second));
        }
    }

    pair<int, int> addeda;

    for (auto p : dirs) {
        if (cur.first + p.first < n && cur.first + p.first > 0 && cur.second + p.second < m && cur.second + p.second > 0) {
            if (grid[cur.first + p.first][cur.second + p.second] != '#') {
                grid[cur.first + p.first][cur.second + p.second] = '#';
                dfs(t + 1, make_pair(cur.first + p.first, cur.second + p.second));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    destx = n - 1, desty = m - 1;

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;
        vector<char> ng;

        for (int j = 0; j < m; j++) {
            ng.push_back(s[j]);
            if (s[j] == '*') {
                blizzard.insert(i, j);
            }
        }

        grid.push_back(ng);
    }

    dfs(0, make_pair(0, 0));
}