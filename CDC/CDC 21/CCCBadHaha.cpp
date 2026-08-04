#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        int k, ck = 0;
        cin >> s >> k;
        stack<pair<char, int>> st;
        vector<char> vs;
        vector<bool> vm(s.size(), false);
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() && s[i] < st.top().first) {
                auto [v, oi] = st.top();
                vs.push_back(v);
                st.pop();
                ck++;
                vm[oi] = true;
                if (ck == k) break;
            }
            if (ck == k) break;
            st.emplace(s[i], i);
        }
        char m = *min_element(vs.begin(), vs.end());
        while (!st.empty() && st.top().first > m && ck != k) {
            auto [v, oi] = st.top();
            vs.push_back(v);
            st.pop();
            ck++;
            vm[oi] = true;
        }
        sort(vs.begin(), vs.end());
        for (int i = 0; i < s.size(); i++) {
            if (!vm[i]) cout << s[i];
        }
        for (char x : vs) {
            cout << x;
        }
        cout << '\n';
    }
}