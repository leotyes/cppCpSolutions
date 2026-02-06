#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, snmin = INT_MAX, fnmin = INT_MAX, snmax = -1, fnmax = -1;
    set<int> smax;

    cin >> n;

    vector<int> vfreq(1001, 0);
    set<int> sfreq, sa;

    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        vfreq[r]++;
        sa.insert(r);
    }

    for (int i = 1; i <= 1000; i++) {
        sfreq.insert(vfreq[i]);
    }

    int emax = *max_element(vfreq.begin(), vfreq.end()), esec;

    sfreq.erase(emax);
    sfreq.erase(0);
    if (sfreq.empty()) {
        cout << abs(*sa.rbegin() - *sa.begin());
        return 0;
    }
    esec = *sfreq.rbegin();

    int c = 0;

    for (int i = 1; i <= 1000; i++) {
        if (vfreq[i] == emax) {
            c++;
            smax.insert(i);
            fnmax = max(fnmax, i);
            fnmin = min(fnmin, i);
        } else if (vfreq[i] == esec) {
            snmax = max(snmax, i);
            snmin = min(snmin, i);
        }
    }

    if (c >= 2) {
        cout << abs(*smax.rbegin() - *smax.begin());
    } else {
        cout << max(abs(fnmax - snmin), abs(fnmin - snmax));
    }
}