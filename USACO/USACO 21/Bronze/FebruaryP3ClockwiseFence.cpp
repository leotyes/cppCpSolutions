#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        vector<pair<int, int>> verts;
        int x = 0, y = 0, a = 0;

        cin >> s;

        switch (s[0]) {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
        }

        for (int j = 1; j < s.length(); j++) {
            if (s[j] != s[j - 1]) {
                verts.emplace_back(x, y);
            }
            switch (s[j]) {
                case 'N':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'W':
                    x--;
                    break;
            }
        }

        for (int j = 0; j < verts.size() - 1; j++) {
            a += verts[j].first * verts[j + 1].second;
        }

        a += verts[verts.size() - 1].first * verts[0].second;

        for (int j = 1; j < verts.size(); j++) {
            a -= verts[j].first * verts[j - 1].second;
        }

        a -= verts[0].first * verts[verts.size() - 1].second;

        if (a < 0) {
            cout << "CW\n";
        } else {
            cout << "CCW\n";
        }
    }
}