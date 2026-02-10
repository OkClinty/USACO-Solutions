#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, g, mi, ma;
    cin >> n;
    int a[n - 1][n - 1], r[n] = {0};
    for (int i = 0; i < n; i++) {
        cin >> g;
        for (int j = 0; j < n - 1 - i; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1) {
        cout << 0 << endl;;
        return 0;
    }
    r[1] = a[0][0];
    mi = 0;
    ma = 1;
    for (int i = 2; i < n; i++) {
        if (a[0][i - 1] > a[0][i - 2] && ((ma > mi && a[0][i - 1] != a[ma][i - ma - 1]) || (mi > ma && a[mi][i - mi - 1] == a[0][i - 1]))) {
            r[i] = r[ma] + a[0][i - 1] - a[0][i - 2];
        } else if (a[0][i - 1] > a[0][i - 2]) {
            r[i] = r[mi] - a[0][i - 1] + a[0][i - 2];
        } else {
            if (r[i - 1] + a[i - 1][0] > r[ma]) {
                r[i] = r[i - 1] - a[i - 1][0];
            } else {
                r[i] = r[i - 1] + a[i - 1][0];
            }
        }
        if (r[i] >= r[ma]) {
            ma = i;
        } else if (r[i] <= r[mi]) {
            mi = i;
        }
    } 
    for (int i = 0; i < n - 1; i++) {
        cout << r[i] << " ";
    }
    cout << r[n - 1] << endl;
    return 0;
}