#include <bits/stdc++.h>
using namespace std;

long long recur(long long a, long long b, int mod) {
    if (b == 0) {
        return 1;
    }
    long long r = recur(a, b / 2, mod);
    if (b % 2 == 1) {
        return (((r * r) % mod) * a) % mod;
    } else {
        return (r * r) % mod;
    }
}

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << recur(a, recur(b, c, 1e9 +  6), 1e9 + 7) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}