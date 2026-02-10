#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t = 1, num;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v[num - 1] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        t += v[i + 1] < v[i];
    }
    cout << t;
    return 0;
}