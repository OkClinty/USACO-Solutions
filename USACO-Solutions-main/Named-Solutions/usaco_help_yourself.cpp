#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long exp(long long a, long long b) {
    if (b == 0) {
        return 1;
    }
    long long r = exp(a, b / 2);
    r = (r * r) % mod;
    if (b % 2 == 1) {
        return (r * a) % mod;
    } else {
        return r;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("help.in");
    ofstream cout ("help.out");
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    vector<long long> p(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (int i = n - 1; i >= 0; i--) {
        p[i] = p[i + 1];
        auto it = upper_bound(v.begin(), v.end(), make_pair(v[i].second + 1, 0));
        if (it != v.end()) {
            p[i] += (distance(it, v.end()) + p[distance(v.begin(), it)]) % mod;
            p[i] %= mod;
        }
    }
    cout << (exp(2, n) - 1 + p[0]) % mod;
    return 0;
}