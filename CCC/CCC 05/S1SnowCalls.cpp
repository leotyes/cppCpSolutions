#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    unordered_map<char, int> m = {{'A', '2'}, {'B', '2'}, {'C', '2'}, {'D', '3'}, {'E', '3'}, {'F', '3'}, {'G', '4'}, {'H', '4'}, {'I', '4'}, {'J', '5'}, {'K', '5'}, {'L', '5'}, {'M', '6'}, {'N', '6'}, {'O', '6'}, {'P', '7'}, {'Q', '7'}, {'R', '7'}, {'S', '7'}, {'T', '8'}, {'U', '8'}, {'V', '8'}, {'W', '9'}, {'X', '9'}, {'Y', '9'}, {'Z', '9'}};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        s.erase(remove(s.begin(), s.end(), '-'), s.end());
        for (char &c : s) {
            if (isalpha(c)) {
                c = m[c];
            }
        }
        cout << string(s.begin(), s.begin() + 3) << '-' << string(s.begin() + 3, s.begin() + 6) << '-' << string(s.begin() + 6, s.begin() + 10) << '\n';
    }
}