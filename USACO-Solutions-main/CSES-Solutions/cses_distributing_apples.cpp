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
    int n, m;
    cin >> n >> m;
    vector<long long> v(2000001);
    v[0] = 1;
    for (int i = 1; i <= 2000000; i++) {
        v[i] = (v[i - 1] * i) % mod;
    }
    cout << (v[n + m - 1] * recur((v[m] * v[n - 1]) % mod, 1e9 + 5)) % mod;
    return 0;
}