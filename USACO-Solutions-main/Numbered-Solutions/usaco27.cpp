#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("div7.out");
    ifstream cin ("div7.in");
    int n, m = 0, l, r;
    cin >> n;
    vector<int> v(n);
    cin >> v[0];
    v[0] %= 7;
    for (int i = 1; i < n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
        v[i] %= 7;
    }
    for (int i = 0; i < 7; i++) {
        l = 0;
        r = n - 1;
        while (l < r) {
            if (v[l] != i) {
                l++;
            }
            if (v[r] != i) {
                r--;
            }
            if (v[l] == i && v[r] == i) {
                m = max(m, r - l);
                break;
            }
        }
    }
    cout << m;
    return 0;
}