#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int x, y, g, c = 0;
    set<pair<string, string>> mustnt, must;
    map<string, int> pgroups;

    cin >> x;

    for (int i = 0; i < x; i++) {
        string n1, n2;
        cin >> n1 >> n2;
        must.insert({n1, n2});
    }

    cin >> y;

    for (int i = 0; i < y; i++) {
        string n1, n2;
        cin >> n1 >> n2;
        mustnt.insert({n1, n2});
    }

    cin >> g;

    for (int i = 0; i < g; i++) {
        string n1, n2, n3;

        cin >> n1 >> n2 >> n3;

        pgroups[n1] = i;
        pgroups[n2] = i;
        pgroups[n3] = i;
    }

    for (pair<string, string> a : must) {
        if (pgroups[a.first] != pgroups[a.second]) {
            c++;
        }
    }

    for (pair<string, string> a : mustnt) {
        if (pgroups[a.first] == pgroups[a.second]) {
            c++;
        }
    }

    cout << c;
    return 0;
}