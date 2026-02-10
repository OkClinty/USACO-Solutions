#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, num, p;
    long long res = 0;
    string a, b;
    cin >> n >> k >> a >> b;
    vector<stack<int>> v(k), vv(k);
    vector<int> u, uu;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            p = i % k;
            if (a[i] == '1') {
                if (!vv[p].empty()) {
                    res += (i - vv[p].top()) / k;
                    vv[p].pop();
                } else {
                    v[p].push(i);
                }
            } else {
                if (!v[p].empty()) {
                    res += (i - v[p].top()) / k;
                    v[p].pop();
                } else {
                    vv[p].push(i);
                }
            }
        }
    }
    for (int i = 0; i < k; i++) {
        while (!v[i].empty()) {
            u.push_back((v[i].top() / k) * k);
            res++;
            v[i].pop();
        }
        while (!vv[i].empty()) {
            uu.push_back((vv[i].top() / k) * k);
            vv[i].pop();
        }
    }
    sort(u.begin(), u.end());
    sort(uu.begin(), uu.end());
    for (int j = 0; j < u.size(); j++) {
        res += abs(u[j] - uu[j]) / k;
    }
    cout << res;
    return 0;
}
