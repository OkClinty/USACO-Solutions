#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t;
    float c;
    cin >> n;
    t = n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            c = 0;
            for (int k = i; k < n - j; k++) {
                c += v[k];
            }
            c /= n - j - i;
            for (int k = i; k < n - j; k++) {
                if (v[k] == c) {
                    t++;
                    break;
                }
            }
        }
    }
    cout << t << "\n";
    return 0;
}