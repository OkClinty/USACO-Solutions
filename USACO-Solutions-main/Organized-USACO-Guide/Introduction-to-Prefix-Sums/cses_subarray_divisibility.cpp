#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0, num;
    long long r = 0;
    cin >> n;
    vector<int> v(n);
    v[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> num;
        c = ((c + num) % n + n) % n;
        r += v[c];
        v[c]++;
    }
    cout << r;
    return 0;
}