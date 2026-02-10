#include <bits/stdc++.h>
using namespace std;

long long recur(vector<long long> v, long long a, long long b) {
    if (v.size() == 0) {
        return abs(a - b);
    } else {
        long long c = v[v.size() - 1];
        v.pop_back();
        return min(recur(v, a + c, b), recur(v, a, b + c));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << recur(v, 0ll, 0ll);
    return 0;
}