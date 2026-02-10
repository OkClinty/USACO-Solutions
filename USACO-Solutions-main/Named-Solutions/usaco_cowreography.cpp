#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    long long r = 0;
    string s1, s2;
    cin >> n >> k >> s1 >> s2;
    set<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == '0') {
                a.insert(i);
            } else {
                b.push_back(i);
            }
        }
    }
    for (int i : b) {
        auto it = prev(a.upper_bound(i));
        r += ((abs(i - (*it)) - 1) / k + 1);
        if (i > (*it)) {
            auto itt = a.lower_bound((i - ((abs(i - (*it)) - 1) / k + 1) * k));
            a.erase(itt); 
        } else {
            auto itt = prev(a.upper_bound((i + ((abs(i - (*it)) - 1) / k + 1) * k)));
            a.erase(itt); 
        }
    }
    cout << r;
    return 0;
}