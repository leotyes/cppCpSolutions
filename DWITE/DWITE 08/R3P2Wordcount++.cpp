#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string line;

    for (int i = 0; i < 5; ++i) {
        getline(cin, line);
        int c = 0;
        int cl = 0;
        for (char ch : line) {
            if (isalpha(ch)) {
                cl++;
            } else {
                if (cl >= 4) c++;
                cl = 0;
            }
        }
        if (cl >= 4) c++;
        cout << c << '\n';
    }
}