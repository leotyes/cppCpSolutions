#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int o;

    cin >> o;

    cout << o << " in Ottawa\n";
    if (o - 300 < 0) {
        cout << 2400 + o - 300 << " in Victoria\n";
    } else {
        cout << o - 300 << " in Victoria\n";
    }
    if (o - 200 < 0) {
        cout << 2400 + o - 200 << " in Edmonton\n";
    } else {
        cout << o - 200 << " in Edmonton\n";
    }
    if (o - 100 < 0) {
        cout << 2400 + o - 100 << " in Winnipeg\n";
    } else {
        cout << o - 100 << " in Winnipeg\n";
    }
    cout << o << " in Toronto\n";
    cout << (o + 100) % 2400 << " in Halifax\n";
    int mins = (o / 100) * 60 + (o % 100) + 90, nh = mins / 60, nm = mins % 60;
    cout << nh * 100 + nm << " in St. John's";
}