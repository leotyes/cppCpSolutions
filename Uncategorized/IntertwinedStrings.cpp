#include <bits/stdc++.h>
using namespace std;

string a, b;
set<string> ss;

void build(string cur, int ai, int bi) {
    if (ai != a.length()) {
        build(cur + a[ai], ai + 1, bi);
    }
    if (bi != b.length()) {
        build(cur + b[bi], ai, bi + 1);
    }
    if (ai == a.length() && bi == b.length()) {
        if (ss.find(cur) == ss.end()) {
            cout << cur << "\n";
            ss.insert(cur);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    build("", 0, 0);
}