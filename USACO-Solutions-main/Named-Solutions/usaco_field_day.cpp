#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c, n, cnt, mult, p, rev, num;
    string s;
    cin >> c >> n;
    p = pow(2, c);
    vector<int> v(p, c), a(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cnt = 0;
        mult = 1;
        for (char ch : s) {
            if (ch == 'H') {
                cnt += mult;
            }
            mult *= 2;
        }
        a[i] = cnt;
        rev = (p - 1) ^ cnt;
        v[rev] = 0;
        q.push(rev);
    }
    while (!q.empty()) {
        num = q.front();
        q.pop();
        for (int i = 0; i < c; i++) {
            if (v[num ^ (1 << i)] > v[num] + 1) {
                v[num ^ (1 << i)] = v[num] + 1;
                q.push(num ^ (1 << i));
            }
        }
    }
    for (int i : a) {
        cout << c - v[i] << "\n";
    }
    return 0;
}