#include <bits/stdc++.h>
using namespace std;

int n, l;
vector<vector<char>> vr(26, vector<char>());

void make(string cur, int ci) {
    cout << cur << "\n";
    if (cur.size() != l) {
        for (int i = ci; i < n; i++) {
            for (int j = 0; j < vr[i].size(); j++) {
                make(cur + vr[i][j], i + 1);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        int s;

        cin >> s;

        for (int j = 0; j < s; j++) {
            char c;

            cin >> c;

            vr[i].push_back(c);
        }
    }

    for (int i = 0; i < vr[0].size(); i++) {
        make(string(1, vr[0][i]), 1);
    }
}