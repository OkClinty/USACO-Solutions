#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0;
    cin >> n;
    for (int i = 5; i <= n; i *= 5) {
        c += n / i;
    }
    cout << c << "\n";
    return 0;
}