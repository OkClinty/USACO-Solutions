#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num = 1;
    cin >> n;
    while (n--) {
        num *= 2;
        num %= 1000000007;
    }
    cout << num << "\n";
    return 0;
}