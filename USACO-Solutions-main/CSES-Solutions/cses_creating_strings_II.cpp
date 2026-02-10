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
    string s;
    long long mlt = 1;
    cin >> s;
    vector<long long> v(1000001);
    vector<int> c(26);
    v[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        v[i] = (v[i - 1] * i) % mod;
    }
    for (char ch : s) {
        c[ch - 'a']++;
    }
    for (int i : c) {
        mlt *= v[i];
        mlt %= mod;
    }
    cout << (v[s.length()] * recur(mlt, 1e9 + 5)) % mod;
    return 0;
}