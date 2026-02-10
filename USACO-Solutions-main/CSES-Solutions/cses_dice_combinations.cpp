#include <bits/stdc++.h>
using namespace std;

int m = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> v(n + 2);
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        v[i] += (v[max(0, i - 1)] + v[max(0, i - 2)] + v[max(0, i - 3)] + v[max(0, i - 4)] + v[max(0, i - 5)] + v[max(0, i - 6)]);
        v[i] %= m;
    }
    cout << v[n + 1];
    return 0;
}