#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    ll n, r = 0;
    cin >> n;
    vector<ll> v(n), val(n, -1);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    val[0] = 1;
    for (int i = 0; i < n; i++) {
        if (val[i] == -1) {
            val[i] = val[i - 1] + n + 1;
            r = i;
        }
        cout << val[i] << "\n";
        if (v[i] > r) {
            for (int j = v[i]; j > i; j--) {
                val[j] = val[i] + n - (v[i] - j);
            }
            r = v[i];
        }
    }
    return 0;
}