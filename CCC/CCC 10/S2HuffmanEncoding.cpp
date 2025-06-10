#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k;
    string s;
    cin >> k;
    map<char, string> b;
    for (int i = 0; i < k; ++i) {
        char l;
        string bc;
        cin >> l >> bc;
        b[l] = bc;
    }
    cin >> s;
    while (s.size() > 0) {
        for (auto it = b.begin(); it != b.end(); ++it) {
            if (s.find(it->second) == 0) {
                cout << it->first;
                s.erase(0, it->second.size());
            }
        }
    }
    return 0;
}