#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        char min_digit = '9';
        for (char c : x) {
            if (c < min_digit)
                min_digit = c;
        }
        cout << (min_digit - '0') << endl;
    }
    return 0;
}
