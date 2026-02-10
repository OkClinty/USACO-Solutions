#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
map<long long, long long> m;

long long recur(long long a, long long b) {
    if (m.find(b) == m.end()) {
        long long res = recur(a, b / 2);
        if (b % 2) {
            m[b] = (((res * res) % mod) * a) % mod;
        } else {
            m[b] = (res * res) % mod;
        }
    }
    return m[b];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        m.clear();
        m[0] = 1;
        cout << recur(a, b) << "\n";
    }
    return 0;
}