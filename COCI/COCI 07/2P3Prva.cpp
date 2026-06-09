#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    string curs = "";
    vector<vector<char>> vc(r, vector<char>(c));
    vector<string> vans;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> vc[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vc[i][j] == '#') {
                if (curs.length() >= 2) {
                    vans.push_back(curs);
                }
                curs = "";
            } else {
                curs += string(1, vc[i][j]);
            }
        }
        if (curs.length() >= 2) {
            vans.push_back(curs);
        }
        curs = "";
    }

    if (!curs.empty()) {
        vans.push_back(curs);
        curs = "";
    }

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            if (vc[i][j] == '#') {
                if (curs.length() >= 2) {
                    vans.push_back(curs);
                }
                curs = "";
            } else {
                curs += string(1, vc[i][j]);
            }
        }
        if (curs.length() >= 2) {
            vans.push_back(curs);
        }
        curs = "";
    }

    if (!curs.empty()) {
        vans.push_back(curs);
        curs = "";
    }

    sort(vans.begin(), vans.end());

    cout << vans[0];
}