#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    map<string, set<string>> mp = {{"Bessie", {}},{"Buttercup", {}},{"Belinda", {}},{"Beatrice", {}},{"Bella", {}},{"Blue", {}},{"Betsy", {}},{"Sue", {}}};
    vector<vector<string>> vs;
    vector<string> curp{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(curp.begin(), curp.end());

    do {
        vs.push_back(curp);
    } while (next_permutation(curp.begin(), curp.end()));

    for (int i = 0; i < n; i++) {
        string a, b;
        for (int j = 0; j < 6; j++) {
            string c;
            if (j == 0) {
                cin >> a;
                continue;
            }
            if (j == 5) {
                cin >> b;
                continue;
            }
            cin >> c;
        }
        mp[a].insert(b);
        mp[b].insert(a);
    }

    for (int i = 0; i < vs.size(); i++) {
        bool fail = false;
        vector<string> curperm = vs[i];
        for (int j = 0; j < 8; j++) {
            string curname = curperm[j];
            if (j == 0) {
                if (mp[curname].size() == 2) {
                    fail = true;
                    break;
                }
                if (mp[curname].size() == 1) {
                    if (mp[curname].find(curperm[1]) == mp[curname].end()) {
                        fail = true;
                        break;
                    }
                }
            } else if (j == 7) {
                if (mp[curname].size() == 2) {
                    fail = true;
                    break;
                }
                if (mp[curname].size() == 1) {
                    if (mp[curname].find(curperm[6]) == mp[curname].end()) {
                        fail = true;
                        break;
                    }
                }
            } else {
                if (mp[curname].size() == 0) {
                    continue;
                }
                if (mp[curname].size() == 1) {
                    if (!(mp[curname].find(curperm[j + 1]) != mp[curname].end() || mp[curname].find(curperm[j - 1]) != mp[curname].end())) {
                        fail = true;
                        break;
                    }
                }
                if (mp[curname].size() == 2) {
                    if (!(mp[curname].find(curperm[j + 1]) != mp[curname].end() && mp[curname].find(curperm[j - 1]) != mp[curname].end())) {
                        fail = true;
                        break;
                    }
                }
            }
        }
        if (!fail) {
            for (string s : curperm) cout << s << "\n";
            break;
        }
    }
}