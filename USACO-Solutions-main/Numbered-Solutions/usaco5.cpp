#include <bits/stdc++.h>
using namespace std;

vector<int> p = {2};
bool b;

void solve() {
    int n, mit = INT_MAX, num;
    cin >> n;
    b = true;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (b) {
            if (num / 4 == 0 || binary_search(p.begin(), p.end(), num)) {
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
    for (int i = 3; i < 250000; i += 2) {
        b = true;
        for (int j : p) {
            if (i % j == 0) {
                b = false;
                break;
            }
        }
        if (b) {
            p.push_back(i);
        }
    }
    while (t--) {
        solve();
    }
    return 0;
}