#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, idx;
    cin >> n;
    vector<int> a(n), d(n);
    iota(d.begin(), d.end(), 1);
    for (int i = 0; i < n; ++i) { 
        cin >> a[i];
        d.erase(remove(d.begin(), d.end(), a[i]), d.end());
    }
    set<int> s;
    for (int i : a) s.insert(i);
    vector<bool> r(s.size(), false);
    vector<int> ss(s.begin(), s.end());
    for (int i : a) {
        if (s.find(i) != s.end()) {
            idx = distance(ss.begin(), find(ss.begin(), ss.end(), i));
            if (r[idx]) {
                if (d.empty()) {
                    cout << ss[idx + 1] << " ";
                } else {
                    cout << d.back() << " ";
                    d.pop_back();
                }
            } else {
                if (idx == ss.size() - 1) {
                    cout << ss[0] << " ";
                    r[0] = true;
                } else {
                    cout << ss[idx + 1] << " ";
                    r[idx + 1] = true;
                }
            }
            
        } else {
            cout << d.back() << " ";
            d.pop_back();
        }
    }
}