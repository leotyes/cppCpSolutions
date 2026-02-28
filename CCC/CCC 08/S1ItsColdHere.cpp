#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, string> mt;

    while (true) {
        string s;
        int t;
        cin >> s >> t;
        mt[t] = s;
        if (s == "Waterloo") break;
    }

    cout << (mt.begin())->second;
}