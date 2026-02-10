#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long n, r = 0, p;
    int k, c;
    cin >> n >> k;
    vector<long long> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
    }
    for (long long i = 1; i < (1 << k); i++) {
        c = 0;
        p = 1;
        for (long long j = 0; j < k; j++) {
            if (i & (1 << j)) {
                c++;
                if (p > n / v[j]) {
                    p = n + 1;
                    break;
                }
                p *= v[j];
            }
        }
        if (c % 2 == 1) {
            r += n / p;
        } else {
            r -= n / p;
        }
    }
    cout << r;
    return 0;
}