#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<string> q;
    map<string, vector<string>> mmout;
    map<string, int> mind, mval;
    map<string, bool> md;

    for (char i = 'A'; i <= 'J'; i++) {
        for (int j = 1; j <= 9; j++) {
            string s;
            cin >> s;
            if (all_of(s.begin(), s.end(), ::isdigit)) {
                q.push(string(1, i) + to_string(j));
                mval[string(1, i) + to_string(j)] = stoi(s);
                md[string(1, i) + to_string(j)] = true;
            } else {
                string curs = "";
                for (int k = 0; k < s.length(); k++) {
                    if (s[k] != '+') {
                        curs.push_back(s[k]);
                    } else {
                        mmout[curs].push_back(string(1, i) + to_string(j));
                        mind[string(1, i) + to_string(j)]++;
                        md[string(1, i) + to_string(j)] = false;
                        curs = "";
                    }
                }
                mmout[curs].push_back(string(1, i) + to_string(j));
                mind[string(1, i) + to_string(j)]++;
                md[string(1, i) + to_string(j)] = false;
                curs = "";
            }
        }
    }

    for (auto [s, ind] : mind) {
        if (ind == 0) {
            q.push(s);
        }
    }

    while (!q.empty()) {
        string fr = q.front();
        q.pop();
        for (string s : mmout[fr]) {
            mind[s]--;
            mval[s] += mval[fr];
            if (mind[s] == 0) {
                q.push(s);
                md[s] = true;
            }
        }
    }

    for (char i = 'A'; i <= 'J'; i++) {
        for (int j = 1; j <= 9; j++) {
            if (md[string(1, i) + to_string(j)]) {
                cout << mval[string(1, i) + to_string(j)] << " ";
            } else {
                cout << "* ";
            }
        }
        cout << "\n";
    }
}