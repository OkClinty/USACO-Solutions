#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num, x, p, m;
    cin >> n;
    vector<int> v(1000001);
    while (n--) {
        cin >> num;
        for (int i = 1; i < sqrt(num) + 1; i++) {
            if (num % i == 0) {
                v[i]++;
                if (i != num / i) {
                    v[num / i]++;
                }
            }
        }
    }
    for (int i = 1000000; i >= 1; i--) {
        if (v[i] > 1) {
            cout << i;
            return 0;
        }
    }
    return 0;
}