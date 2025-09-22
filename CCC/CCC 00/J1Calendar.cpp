#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int a, b, c = 1, d = 1;
    cin >> a >> b;
    cout << "Sun Mon Tue Wed Thr Fri Sat\n";
    for (; c < a; c++) {
        cout << "    ";
    }
    for (; d <= b; ++d, ++c) {
        cout << setw(3) << d;
        if (c % 7 == 0 || d == b) {
            cout << '\n';
        } else {
            cout << ' ';
        }
    }
    return 0;
}