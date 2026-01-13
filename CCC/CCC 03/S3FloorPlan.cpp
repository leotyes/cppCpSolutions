#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;

    cin >> n >> r >> c;

    vector<string> vg(r);
    vector<int> vr;

    for (int i = 0; i < r; i++) {
        cin >> vg[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vg[i][j] == '.') {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                vr.push_back(0);
                vg[q.front().first][q.front().second] = 'V';
                while (!q.empty()) {
                    vr.back()++;
                    if (q.front().first != r - 1 && vg[q.front().first + 1][q.front().second] == '.') {
                        vg[q.front().first + 1][q.front().second] = 'V';
                        q.push(make_pair(q.front().first + 1, q.front().second));
                    }
                    if (q.front().second != c - 1 && vg[q.front().first][q.front().second + 1] == '.') {
                        vg[q.front().first][q.front().second + 1] = 'V';
                        q.push(make_pair(q.front().first, q.front().second + 1));
                    }
                    if (q.front().first != 0 && vg[q.front().first - 1][q.front().second] == '.') {
                        vg[q.front().first - 1][q.front().second] = 'V';
                        q.push(make_pair(q.front().first - 1, q.front().second));
                    }
                    if (q.front().second != 0 && vg[q.front().first][q.front().second - 1] == '.') {
                        vg[q.front().first][q.front().second - 1] = 'V';
                        q.push(make_pair(q.front().first, q.front().second - 1));
                    }
                    q.pop();
                }
            }
        }
    }

    sort(vr.begin(), vr.end(), greater<int>());

    for (int i = 0; i < vr.size(); i++) {
        if (n - vr[i] < 0) {
            if (i == 1) {
                cout << "1 room, " << n << " square metre(s) left over";
            } else {
                cout << i << " rooms, " << n << " square metre(s) left over";
            }
            n -= vr[i];
            break;
        } else {
            n -= vr[i];
        }
    }

    if (n >= 0) {
        if (vr.size() == 1) {
            cout << "1 room, " << n << " square metre(s) left over";
        } else {
            cout << vr.size() << " rooms, " << n << " square metre(s) left over";
        }
    }
}