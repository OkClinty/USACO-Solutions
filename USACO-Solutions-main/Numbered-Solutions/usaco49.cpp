#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("shuffle.out");
    ifstream cin ("shuffle.in");
    int n, c = 3;
    cin >> n;
    vector<int> v(n);
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (c--) {
        for (int i = 0; i < n; i++) {
            b[i] = a[v[i] - 1];
        }
        a = b;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}