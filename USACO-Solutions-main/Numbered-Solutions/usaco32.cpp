#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("lostcow.out");
    ifstream cin ("lostcow.in");
    int x, y, p, c = 1, s = 0;
    cin >> x >> y;
    p = x;
    while (p != y) {
        if (p == x + c) {
            c *= -2;
        }
        if (p < x + c) {
            p++;
        } else {
            p--;
        }
        s++;
    }
    cout << s;
    return 0;
}