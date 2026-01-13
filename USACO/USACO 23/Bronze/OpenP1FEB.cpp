#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, emin = 0, emax = 0;
    string s;

    cin >> n >> s;

    int fnf = 0, lnf = n - 1;
    int stmax = 0, enmax = 0;

    for (; fnf < n && s[fnf] == 'F'; fnf++) stmax++;

    for (; lnf >= 0 && s[lnf] == 'F'; lnf--) enmax++;

    if (s.length() == count(s.begin(), s.end(), 'F')) {
        cout << s.length() << "\n";
        for (int i = 0; i < s.length(); i++) {
            cout << i << "\n";
        }
        return 0;
    }

    for (int i = fnf; i <= lnf; i++) {
        if (s[i] == 'F') {
            int fs = 1;
            int last = i + 1;
            for (; last <= lnf && s[last] == 'F'; last++) {
                fs++;
            }
            if (i > fnf && i <= lnf) {
                if (s[i - 1] == s[last]) {
                    if (fs % 2 == 0) {
                        emin++;
                        emax += fs + 1;
                    } else {
                        emax += fs + 1;
                    }
                } else {
                    if (fs % 2 == 0) {
                        emax += fs;
                    } else {
                        emin++;
                        emax += fs;
                    }
                }
            }
            if (last != i + 1) i = last - 1;
        } else if (i < n - 1 && s[i] == s[i + 1]) {
            emin++;
            emax++;
        }
    }

    emax += enmax + stmax;

    if (enmax == 0 && stmax == 0) {
        cout << (emax - emin) / 2 + 1 << "\n";
        for (int i = emin; i <= emax; i += 2) {
            cout << i << "\n";
        }
    } else {
        cout << emax - emin + 1 << "\n";
        for (int i = emin; i <= emax; i++) {
            cout << i << "\n";
        }
    }


}