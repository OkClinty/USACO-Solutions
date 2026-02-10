#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long recur(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long r = recur(a, b / 2);
    if (b % 2) {
        return (((r * r) % mod) * a) % mod;
    } else {
        return (r * r) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long a, b, d = 1, dd = 1, s = 1, p = 1, num = 1;
    bool bl = true;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        d *= b + 1;
        d %= mod;
        s *= (((recur(a, b + 1) - 1 + mod) % mod) * recur(a - 1, mod - 2)) % mod;
        s %= mod;
        num *= recur(a, b);
        num %= mod;
        p = (recur(p, b + 1) * recur(recur(a, b * (b + 1) / 2), dd)) % mod;
        dd *= b + 1;
        dd %= (mod - 1);
    }
    cout << d << " " << s << " " << p;
    return 0;
}