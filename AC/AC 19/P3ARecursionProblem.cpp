#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string x, ax;
    getline(cin, x);
    stack<string> s;

    for (char c : x) {
        if (!(c == '(' || c == ')')) {
            ax.push_back(c);
        }
    }

    bool isint = true;

    for (char c : ax) {
        if (c == ' ') {
            isint = false;
        }
    }

    if (isint) {
        cout << ax;
        return 0;
    }

    string curs = "";
    vector<int> vt;

    for (char c : ax) {
        if (c == '+') continue;
        if (c == ' ') {
            if (curs == "") continue;
            vt.push_back(stoi(curs));
            curs = "";
            continue;
        }
        curs.push_back(c);
    }
    vt.push_back(stoi(curs));

    cout << accumulate(vt.begin(), vt.end(), 0);

}