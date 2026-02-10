#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    if (n > 0) {
        cout << "0\n";
    }
    if (n > 1) {
        cout << "6\n";
    }
    if (n > 2) {
        cout << "28\n";
    }
    for (long long i = 4; i <= n; i++) {
        cout << (4 * (i * i - 3) + 8 * (i * i - 4) + 4 * (i - 3) * (i * i - 5) + 4 * (i - 4) * (i * i - 7) + (i - 4) * (i - 4) * (i * i - 9)) / 2 << "\n";
    }
    return 0;
}