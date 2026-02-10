#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

const int mod = 1000000007;

long long exp(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long r = exp(a, b / 2);
    r *= r;
    r %= mod;
    if (b % 2 == 1) {
        r *= a;
        r %= mod;
    }
    return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long k, n, l, o = 0, r = 1;
    string s;
    cin >> k >> n >> l >> s;
    vector<long long> f(1000005);
    f[0] = 1;
    for (int i = 1; i < 1000005; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'O') {
            o++;
        } else {
            r *= (((f[o] * exp(f[o - k], mod - 2)) % mod) * exp(f[k], mod - 2)) % mod;
            r %= mod;
            o -= k;
        }
    }
    cout << exp(r, (l % (mod - 1)));
    return 0;
}
