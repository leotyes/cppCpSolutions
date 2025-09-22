#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> ns;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        if (ns.find(l) != ns.end()) {
            ns[l] += 1;
        } else {
            ns[l] = 1;
        }
    }
    
}