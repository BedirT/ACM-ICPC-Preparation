// Solution for the problem: GCD of large numbers
// https://www.codechef.com/problems/GCD2

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        string b;
        cin >> a >> b;
        if (a == 0) {
            cout << b << endl;
            continue;
        }
        int b_mod_a = 0;
        for (int j = 0; j < b.size(); ++j) {
            b_mod_a = (b_mod_a * 10 + (b[j] - '0')) % a;
        }
        cout << gcd(a, b_mod_a) << endl;
    }
    return 0;
}