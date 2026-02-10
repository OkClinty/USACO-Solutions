#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c, n, m, t;
    string str;
    cin >> c >> n;
    vector<string> v(n);
    vector<string> arr;
    set<string> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (s.find(v[i]) == s.end()) {
            arr.push_back(v[i]);
            s.insert(v[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        m = 0;
        for (string st : arr) {
            t = 0;
            for (int j = 0; j < c; j++) {
                t += (v[i][j] != st[j]);
            }
            m = max(m, t);
            if (m == c) {
                break;
            }
        }
        cout << m << "\n";
    }
    return 0;
}