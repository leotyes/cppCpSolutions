#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a, n, aa;
    vector<char> va;
    int ia, in;
    cin >> n;
    a = n;
    if (n.substr(1) == string(n.size() - 1, '0') || n.size() == 1) {
        cout << 0;
        return 0;
    }
    a = string(1, a[0] + 1);
    if (a == ":") {
        a = '1';
        a += string(n.size(), '0');
        for (int i = 0; i < n.size(); ++i) {
            ia = a.size() - i - 1;
            in = n.size() - i - 1;
            if (a[ia] - n[in] < 0) {
                a[ia] += 10;
                a[ia - 1] -= 1;
            }
            va.push_back((a[ia] - n[in]) + '0');
        }
        aa = string(va.begin(), va.end());
        reverse(aa.begin(), aa.end());
        aa = aa.substr(aa.find_first_not_of('0'));
        cout << aa;
        return 0;
    }
    a += string(n.size() - 1, '0');
    for (int i = 0; i < n.size(); ++i) {
        ia = a.size() - i - 1;
        in = n.size() - i - 1;
        if (a[ia] - n[in] < 0) {
            a[ia] += 10;
            a[ia - 1] -= 1;
        }
        va.push_back((a[ia] - n[in]) + '0');
    }
    aa = string(va.begin(), va.end());
    reverse(aa.begin(), aa.end());
    aa = aa.substr(aa.find_first_not_of('0'));
    cout << aa;
    return 0;
}