#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, mind = INT_MAX;
    cin >> n;
    vector<char> vc(n);
    vector<int> vo;
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        if (vc[i] == '1') {
            vo.push_back(i);
        }
    }

    for (int i = 0; i < vo.size() - 1; i++) {
        mind = min(mind, vo[i + 1] - vo[i]);
    }
    mind = min(mind, vo[0]);
    mind = min(mind, (int)vo.size() - 1 - vo[vo.size() - 1]);


}