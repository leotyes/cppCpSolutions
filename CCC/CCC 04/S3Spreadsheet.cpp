#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<string> q;
    map<string, vector<string>> mind, moutd;

    for (char i = 'A'; i <= 'J'; i++) {
        for (int j = 1; j <= 9; j++) {
            string s;
            cin >> s;
            if (all_of(s.begin(), s.end(), ::isdigit)) {
                q.push(string(1, i) + to_string(j));
            } else {
                string curs = "";
                for (int k = 0; k < s.length(); k++) {
                    if (s[k] != '+') {
                        curs.push_back(s[k]);
                    } else {
                        mind[string(1, i) + to_string(j)].push_back(curs);
                        moutd[curs].push_back(string(1, i) + to_string(j));
                        curs = "";
                    }
                }
            }
        }
    }

    while (!q.empty()) {
        
    }
}