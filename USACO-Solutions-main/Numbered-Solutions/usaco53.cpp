#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("gymnastics.out");
    ifstream cin ("gymnastics.in");
    int k, n, c = 0, l, r;
    bool b;
    cin >> k >> n;
    vector<vector<int>> v(k);
    for (int i = 0; i < k; i++) {
        v[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            b = true;
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < n; y++) {
                    if (v[x][y] == i) {
                        l = y;
                    } else if (v[x][y] == j) {
                        r = y;
                    }
                }
                if (r > l) {
                    b = false;
                    break;
                }
            }
            if (b) {
                c++;
            }
        }
    }
    cout << c << endl;
    return 0;
}