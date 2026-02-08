#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<string> vs(n + 1), vo(n);
    map<char, vector<char>> mout;
    map<char, int> mind;
    map<char, char> mans;
    map<char, bool> mf = {{'a', true}, {'b', true}, {'c', true}, {'d', true}, {'e', true}, {'f', true}, {'g', true}, {'h', true}, {'i', true}, {'j', true}, {'k', true}, {'l', true}, {'m', true}, {'n', true}, {'o', true}, {'p', true}, {'q', true}, {'r', true}, {'s', true}, {'t', true}, {'u', true}, {'v', true}, {'w', true}, {'x', true}, {'y', true}, {'z', true}};

    for (int i = 1; i <= n; i++) {
        cin >> vs[i];
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vo[i] = vs[x];
    }

    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            int j = 0;
            bool b = false;
            while (vo[i][j] == vo[i + 1][j]) {
                j++;
                if (vo[i + 1].length() == j) {
                    cout << "NE\n";
                    return 0;
                } else if (vo[i].length() == j) {
                    b = true;
                    break;
                }
            }
            if (b) continue;
            mout[vo[i][j]].push_back(vo[i + 1][j]);
            mind[vo[i + 1][j]]++;
            if (mind.find(vo[i][j]) == mind.end()) mind[vo[i][j]] = 0;
            mf[vo[i + 1][j]] = false;
        }
    }

    queue<char> q;
    char cur = 'a';

    for (auto [ch, c] : mind) {
        if (c == 0) {
            q.push(ch);
            mans[ch] = cur;
            mf[ch] = true;
            cur++;
        }
    }

    while (!q.empty()) {
        char fr = q.front();
        q.pop();
        for (char x : mout[fr]) {
            mind[x]--;
            if (mind[x] == 0) {
                q.push(x);
                mans[x] = cur;
                cur++;
                mf[x] = true;
            }
        }
    }

    for (auto [ch, f] : mf) {
        if (!f) {
            cout << "NE\n";
            return 0;
        }
    }

    cout << "DA\n";

    for (char c = 'a'; c <= 'z'; c++) {
        if (mans.find(c) != mans.end()) {
            cout << mans[c];
        } else {
            cout << cur;
            cur++;
        }
    }

    cout << "\n";
}