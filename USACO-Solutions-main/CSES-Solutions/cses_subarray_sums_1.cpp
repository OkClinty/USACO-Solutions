#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, p = 0, r = 0;
    long long c = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        c += v[i];
        while (p < i && c > x) {
            c -= v[p];
            p++;
        }
        if (c == x) {
            r++;
        }
    }
    cout << r << "\n";
    return 0;
}