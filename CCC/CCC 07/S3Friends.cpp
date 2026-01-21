#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c = 1;

    cin >> n;

    map<int, int> next, cid, cpos, vis, csize;
    set<int> sv;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        next[a] = b;
        sv.insert(a);
        sv.insert(b);
    }

    for (int i : sv) {
        int cur = i, cc = 0;
        bool b = false;
        stack<int> s;

        while (vis[cur] != 2) {
            if (vis[cur] == 1) {
                b = true;
                vector<int> vc;
                while (s.top() != cur) {
                    vc.push_back(s.top());
                    vis[s.top()] = 2;
                    s.pop();
                }
                vc.push_back(s.top());
                vis[s.top()] = 2;
                s.pop();
                reverse(vc.begin(), vc.end());
                csize[c] = vc.size();
                for (int j = 0; j < vc.size(); j++) {
                    cid[vc[j]] = c;
                    cpos[vc[j]] = j;
                }
                break;
            }
            vis[cur] = 1;
            s.push(cur);
            cur = next[cur];
            cc++;
        }
        while (!s.empty()) {
            cpos[s.top()] = -1;
            cid[s.top()] = -1;
            vis[s.top()] = 2;
            s.pop();
        }
        if (b) c++;
    }

    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (cid[a] == cid[b] && cid[a] > 0) {
            cout << "Yes " << (cpos[b] - cpos[a] - 1 + csize[cid[a]]) % csize[cid[a]] << "\n";
        } else {
            cout << "No\n";
        }
    }
}