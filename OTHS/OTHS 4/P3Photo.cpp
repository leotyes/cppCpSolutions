#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r, c, cc = 0;
    cin >> r >> c;
    stack<int> st;
    vector<int> a(r * c);
    map<int, int> m;
    for (int i = 0; i < (r * c); ++i) {
        int in;
        cin >> in;
        m[in]++;
    }
    for (int i = 0; i < c; ++i) {
        st = stack<int>();
        for (auto it = m.begin(); it != m.end(); ++it) { 
            if (it->second != 0) {
                it->second--;
                st.push(it->first);
            } else {
                continue;
            }
        }
        cc += st.size();
    }
    cout << cc;
}