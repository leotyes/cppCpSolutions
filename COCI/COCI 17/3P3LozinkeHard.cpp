#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    map<string, int> subpwfreq;

    int q;

    cin >> q;

    for (int i = 0; i < q; i++) {
        int n, c = 0;
        string s;

        cin >> n >> s;

        if (n == 1) {
            set<string> toadd;
            for (int j = 0; j < s.length(); j++) {
                for (int k = j; k < s.length(); k++) {
                    toadd.insert(s.substr(j, k - j + 1));
                }
            }
            for (string subpw : toadd) {
                subpwfreq[subpw]++;
            }
        } else {
            cout << subpwfreq[s] << "\n";
        }
    }
}