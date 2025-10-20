#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    string in[] = { a, b, c, d, e };
    stack<char> s;
    stack<char> s2;
    for (int i = 0; i <= 4; i++) {
        for (int z = 0; z <= in[i].length() - 1; z++) {
            if (!isalnum(in[i][z])) {
                s.push(in[i][z]);
            }
        }
        while (!s.empty()) {
            if (s.top() == ']' || s.top() == '}' || s.top() == ')') {
                s2.push(s.top());
                s.pop();
            }
            else {
                if (!s2.empty()) {
                    if (s.top() == '[') {
                        if (s2.top() == ']') {
                            s.pop();
                            s2.pop();
                        }
                        else {
                            cout << "not balanced\n";
                            break;
                        }
                    }
                    else if (s.top() == '{') {
                        if (s2.top() == '}') {
                            s.pop();
                            s2.pop();
                        }
                        else {
                            cout << "not balanced\n";
                            break;
                        }
                    }
                    else if (s.top() == '(') {
                        if (s2.top() == ')') {
                            s.pop();
                            s2.pop();
                        }
                        else {
                            cout << "not balanced\n";
                            break;
                        }
                    }
                }
                else {
                    cout << "not balanced\n";
                    break;
                }
            }
        }
        if (s.empty()) {
            cout << "balanced\n";
        }
        while (!s.empty()) {
            s.pop();
        }
        while (!s2.empty()) {
            s2.pop();
        }
    }
}