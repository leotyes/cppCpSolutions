#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int s1, s2, s3, s4, s5, d;
    
    cin >> s1 >> s2 >> s3 >> s4 >> s5 >> d;
    
    vector<int> vs = {s1, s2, s3, s4, s5};
    
    sort(vs.begin(), vs.end());
    
    cout << (vs[1] + vs[2] + vs[3]) * d;
}