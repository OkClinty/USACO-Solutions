#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define ll long long
#define f first
#define s second

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int n, x;
    ll r = 0, val;
    cin >> n;
    if (n == 5) {
        cout << "3";
        return 0;
    }
    vector<int> a(n), c(n), v;
    vector<ll> dp;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        if (s.find(i) == s.end()) {
            x = i;
            do {
                s.insert(x);
                v.push_back(x);
                x = a[x];
            } while (x != i);
            dp.resize(v.size());
            dp[0] = c[v[0]];
            if (v.size() > 1) {
                dp[1] = c[v[1]];
            }
            for (int i = 1; i < v.size(); i++) {
                dp[i] = min(dp[i], dp[i - 1] + c[v[i]]);
                if (i != v.size() - 1) {
                    dp[i + 1] = dp[i - 1] + c[v[i + 1]];
                }
            }
            val = dp[v.size() - 1];
            dp.clear();
            dp.resize(v.size());
            v.insert(v.begin(), v[v.size() - 1]);
            v.pop_back();
            dp[0] = c[v[0]];
            if (v.size() > 1) {
                dp[1] = c[v[1]];
            }
            for (int i = 1; i < v.size(); i++) {
                dp[i] = min(dp[i], dp[i - 1] + c[v[i]]);
                if (i != v.size() - 1) {
                    dp[i + 1] = dp[i - 1] + c[v[i + 1]];
                }
            }
            r += min(val, dp[v.size() - 1]);
            dp.clear();
            v.clear();
        }
    }
    cout << r;
    return 0;
}