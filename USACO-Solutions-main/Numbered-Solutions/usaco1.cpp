#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, t = 0, tut;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    t = tut = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        if ((n - i) * v[i] >= t) {
            t = (n - i) * v[i];
            tut = v[i];
        }
    }
    cout << t << " " << tut;
    return 0;
}