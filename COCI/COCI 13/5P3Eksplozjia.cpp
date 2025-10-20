#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, b, res = "";

    cin >> s >> b;

    for (char c : s) {
        res.push_back(c);
        if (res.size() >= b.size()) {
            if (res.substr(res.size() - b.size(), b.size()) == b) {
                for (int i = 0; i < b.size(); i++) res.pop_back();
            }
        }
    }

    cout << (res == "" ? "FRULA" : res);
}