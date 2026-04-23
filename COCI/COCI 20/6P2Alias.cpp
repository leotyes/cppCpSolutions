    #include <bits/stdc++.h>
    using namespace std;
    #define int long long

    signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m, q;
        cin >> n >> m;
        map<string, vector<pair<int, string>>> madj;

        for (int i = 0; i < m; i++) {
            string x, y;
            int t;
            cin >> x >> y >> t;
            madj[x].emplace_back(t, y);
        }

        cin >> q;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;

        for (int i = 0; i < q; i++) {
            map<string, int> md;
            string a, b;
            cin >> a >> b;
            md[a] = 0;
            pq.emplace(0, a);
            while (!pq.empty()) {
                auto [w, u] = pq.top();
                pq.pop();
                for (auto [nw, v] : madj[u]) {
                    if (md.find(v) == md.end() || md[u] + nw < md[v]) {
                        md[v] = md[u] + nw;
                        pq.emplace(nw, v);
                    }
                }
            }
            if (md.find(b) == md.end()) {
                cout << "Roger\n";
            } else {
                cout << md[b] << "\n";
            }
        }
    }