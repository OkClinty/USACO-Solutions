#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    long long c = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        c += v[i];
    }
    sort(v.begin(), v.end());
    if (v[n - 1] > c - v[n - 1]) {
        cout << 2ll * v[n - 1]; 
    } else {
        cout << c;
    }
    return 0;
}