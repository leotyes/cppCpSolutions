#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int b, p, t;
    
    cin >> b >> t >> p;
    
    if (t - p < b) {
        cout << "N";
    } else {
        cout << "Y " << t - p - b;
    }
}