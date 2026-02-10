#include <bits/stdc++.h>
using namespace std;

vector<bool> p(5000005);
bool b;

void solve() {
    int n, mit = INT_MAX, num;
    cin >> n;
    b = true;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (b) {
            if (num / 4 == 0 || p[num]) {
                mit = num;
                b = false;
            }
            if (num / 4 < mit / 4) {
                mit = num;
            } 
        }
    }
    if (mit % 4 == 0) {
        cout << "Farmer Nhoj\n";
    } else {
        cout << "Farmer John\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 1; i < 5000005; i++) {
        p[i] = true;
    }
    for (int i = 2; i < 5000005; i++) {
        if (p[i]) {
            for (int j = i + i; j < 5000005; j += i) {
                p[j] = false;
            }
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}