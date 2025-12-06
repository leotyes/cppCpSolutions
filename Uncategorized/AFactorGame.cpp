#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> vn(n), vf(1000001, 0);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> vn[i];
        freq[vn[i]]++;
    }

    for (auto it = freq.begin(); it != freq.end(); it++) {
        if (it->second != 0) {
            for (int j = 2 * it->first; j < 1000001; j += it->first) {
                vf[j] += it->second;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << vf[vn[i]] + freq[vn[i]] - 1 << "\n";
    }
}