#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, o;

    cin >> n;

    map<int, int> mfreq;
    vector<int> vans(4001, 0);

    for (int i = 0; i < n; i++) {
        int li;
        cin >> li;
        mfreq[li]++;
    }

    for (auto i = mfreq.begin(); i != mfreq.end(); i++) {
        auto j = i;
        vans[j->first + i->first] += j->second / 2;
        j++;
        for (; j != mfreq.end(); j++) {
            vans[j->first + i->first] += min(j->second, i->second);
        }
    }

    m = *max_element(vans.begin(), vans.end());
    o = count(vans.begin(), vans.end(), m);
    cout << m << " " << o << "\n";
}