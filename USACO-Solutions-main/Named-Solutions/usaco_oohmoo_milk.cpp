#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, d, a, b, res = 0, l = 0, r = 10'000'000'000, m, sum;
    cin >> n >> d >> a >> b;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n - a; i++) {
        res += (v[i] * v[i]) % mod;
        res %= mod;
    }
    for (int i = n - a; i < n - b; i++) {
        v[i] += d;
    }
    while (l < r) {
        m = (l + r + 1) / 2;
        sum = 0;
        for (int i = n - a; i < n - b; i++) {
            sum += max(v[i] - m, 0ll);
        }
        for (int i = n - b; i < n; i++) {
            sum -= max(m - v[i], 0ll);
        }
        if (sum < 0) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    sum = 0;
    for (int i = n - a; i < n - b; i++) {
        if (v[i] > l) {
            res += (l * l) % mod;
            sum += v[i] - l;
        } else {
            res += (v[i] * v[i]) % mod;
        }
        res %= mod;
    }
    for (int i = n - b; i < n; i++) {
        if (v[i] < l) {
            res += (l * l) % mod;
            sum -= l - v[i];
        } else {
            res += (v[i] * v[i]) % mod;
        }
        res %= mod;
    }
    cout << (res + sum * (2 * l + 1)) % mod;
    return 0;
}
