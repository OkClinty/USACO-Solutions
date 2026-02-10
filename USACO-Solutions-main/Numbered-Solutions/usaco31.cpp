#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("crossroad.out");
    ifstream cin ("crossroad.in");
    int n, x, y, c = 0;
    cin >> n;
    vector<int> v(10);
    for (int i = 0; i < 10; i++) {
        v[i] = -1;
    }
    while (n--) {
        cin >> x >> y;
        if (v[x - 1] != -1 && v[x - 1] ^ y) {
            c++;
        }
        v[x - 1] = y;
    }
    cout << c;
    return 0;
}