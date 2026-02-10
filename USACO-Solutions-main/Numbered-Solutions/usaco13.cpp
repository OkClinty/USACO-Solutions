#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("bcount.out");
    ifstream fin ("bcount.in");    
    int n, q, num, x, y;
    fin >> n >> q;
    vector<vector<int>> v(4);
    for (int i = 1; i <= 3; i++) {
        v[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            v[j][i] = v[j][i - 1];
        }
        fin >> num;
        v[num][i]++;
    }
    while (q--) {
        fin >> x >> y;
        fout << v[1][y] - v[1][x - 1] << " " << v[2][y] - v[2][x - 1] << " " << v[3][y] - v[3][x - 1] << "\n";
    }
    return 0;
}