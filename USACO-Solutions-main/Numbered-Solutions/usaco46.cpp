#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("mixmilk.out");
    ifstream cin ("mixmilk.in");
    int A, a, B, b, C, c, t = 0, r = 100, num;
    cin >> A >> a >> B >> b >> C >> c;
    while (r--) {
        if (t == 0) {
            num = min(a, B - b);
            a -= num;
            b += num;
        } else if (t == 1) {
            num = min(b, C - c);
            b -= num;
            c += num;
        } else {
            num = min(c, A - a);
            c -= num;
            a += num;
        }
        t++;
        t %= 3;
    }
    cout << a << "\n" << b << "\n" << c << "\n";
    return 0;
}