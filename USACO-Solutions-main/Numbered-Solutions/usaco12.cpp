#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("maxcross.out");
    ifstream fin ("maxcross.in");    
    int n, k, b, x, y, c = 0, min;
    fin >> n >> k >> b;
    vector<bool> v(n + 1);
    while (b--) {
        fin >> x;
        v[x] = true;
    }
    x = 1;
    y = k + 1;
    for (int i = 1; i <= k; i++) {
        c += v[i];
    }
    min = c;
    while (y <= n + 1) {
        c -= v[x];
        c += v[y];
        x++;
        y++;
        if (c < min) {
            min = c;
        }
    }
    fout << min;
    return 0;
}