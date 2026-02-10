#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

void solve() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    complex<long long> p1(x1, y1), p2(x2, y2), p3(x3, y3);
    if ((conj(p3 - p1) * (p3 - p2)).imag() > 0) {
        cout << "LEFT\n";
    } else if ((conj(p3 - p1) * (p3 - p2)).imag() < 0) {
        cout << "RIGHT\n";
    } else {
        cout << "TOUCH\n";
    }
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