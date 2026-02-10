#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x, z = 1;
    long long c = 0, r = 0;
    cin >> n >> x;
    vector<int> v(n);
    multiset<long long> ms;
    ms.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        c += v[i];
        if (c == x) {
            r += z;
        } else {
            r += ms.count(c - x);   
        }
        if (c == 0) {
            z++;
        }
        ms.insert(c);
    }
    cout << r << "\n";
    return 0;
}