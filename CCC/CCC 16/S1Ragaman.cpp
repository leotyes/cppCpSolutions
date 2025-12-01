#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;

    cin >> a >> b;

    map<char, int> freqa, freqb;

    for (int i = 0; i < a.length(); i++) {
        freqa[a[i]]++;
        if (b[i] != '*') {
            freqb[b[i]]++;
        }
    }

    for (auto it = freqb.begin(); it != freqb.end(); it++) {
        if (freqa[it->first] < it->second) {
            cout << 'N';
            return 0;
        }
    }

    cout << 'A';
}