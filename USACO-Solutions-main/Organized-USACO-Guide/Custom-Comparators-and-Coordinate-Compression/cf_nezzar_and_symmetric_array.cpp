#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    long long n, c = 0;
    cin >> n;
    vector<long long> v(n * 2);
    set<long long> s;
    for (int i = 0; i < n * 2; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<long long>());
    for (long long i = 0; i < n * 2; i += 2) {
        if (v[i] != v[i + 1] || (v[i] - 2 * c) % (n * 2 - i) != 0 || s.find((v[i] - 2 * c) / (n * 2 - i)) != s.end() || (v[i] - 2 * c) / (n * 2 - i) == 0 || c * 2 > v[i]) {
            cout << "NO\n";
            return;
        }
        s.insert((v[i] - 2 * c) / (n * 2 - i));
        c += ((v[i] - 2 * c) / (n * 2 - i));
    }
    cout << "YES\n";
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}