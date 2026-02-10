#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, r = 0, s = (long long)floor(sqrt(n)) + 1;
    cin >> n;
    for (long long i = 1; i < s; i++) {
        r += n / i * i;
        r %= 1000000007;
    }
    for (long long i = s; i < n; i += 1000000) {
        if (i + 1000000 >= n) {
            r += (((n - i + 1) / 2) * ((i + n) % 1000000007)) % 1000000007;
            if ((n - i + 1) % 2 == 1) {
                r += (n + i) / 2;
            }
        } else {
            r += (500000 * ((2 * i + 999999) % 1000000007)) % 1000000007;
        }
        r %= 1000000007;
    }
    cout << r << "\n";
    return 0;
}