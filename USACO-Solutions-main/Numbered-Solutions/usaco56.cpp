#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("mountains.out");
    ifstream cin ("mountains.in");
    long long n, a, b, e, c;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a - b, a + b};
    }
    sort(v.begin(), v.end());
    e = v[0].second;
    c = (n == 1 || v[0].first != v[1].first);
    for (int i = 1; i < n; i++) {
        c += v[i].second > e;
        e = max(e, v[i].second);
    }
    cout << c;
    return 0;
}