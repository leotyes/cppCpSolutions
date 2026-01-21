#include <bits/stdc++.h>
using namespace std;

map<char, set<char>> madj;
map<char, bool> mvis;
vector<string> vans;
map<pair<char, char>, bool> md;
bool f = false;

void dfs(char cur, pair<char, char> rem) {
    if (md[rem]) {
        f = true;
        return;
    }
    for (char x : madj[cur]) {
        if (!mvis[x]) {
            mvis[x] = true;
            if (x == 'B') {
                md[rem] = true;
                f = true;
                return;
            }
            dfs(x, rem);
            if (f) return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    set<pair<char, char>> sadj;

    while (true) {
        char a, b;
        cin >> a >> b;
        if (a == '*' && b == '*') break;
        madj[a].insert(b);
        madj[b].insert(a);
        sadj.emplace(a, b);
    }

    dfs('A', make_pair('0', '0'));
    if (!f) {
        cout << "There are 0 disconnecting roads.\n";
        return 0;
    }

    f = false;
    mvis.clear();

    for (auto x : sadj) {
        madj[x.first].erase(x.second);
        madj[x.second].erase(x.first);
        mvis['A'] = true;
        dfs('A', x);
        if (!f) {
            vans.push_back(string(1, x.first) + x.second);
        }
        mvis.clear();

        f = false;
        madj[x.first].insert(x.second);
        madj[x.second].insert(x.first);
    }

    for (auto x : vans) {
        cout << x << "\n";
    }

    cout << "There are " << vans.size() << " disconnecting roads.\n";
}