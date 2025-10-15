#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string t, s, current;

    int cc = 0;

    cin >> t >> s;

    map<char, int> freqs, freqc;

    for (char c : s) {
        freqs[c]++;
        cc++;
    }

    for (char c : t) {
        freqc[c]++;
        cc--;
        if (cc == 0) {
            break;
        }
    }

    cc = 0;

    while (cc <= t.size() - s.size()) {
        current = t.substr(cc, s.size());
        string doubled = current + current;
        if (doubled.find(s) != string::npos) {
            cout << "yes";
            return 0;
        }
        cc++;
    }

    cout << "no";
}