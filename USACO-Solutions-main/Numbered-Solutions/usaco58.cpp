#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("paintbarn.out");
    ifstream cin ("paintbarn.in");
    int n, k, c = 0, cnt = 0, x1, y1, x2, y2;
    cin >> n >> k;
    vector<vector<int>> ul(1001, vector<int>(1001)), ur(1001, vector<int>(1001)), dl(1001, vector<int>(1001)), dr(1001, vector<int>(1001));
    vector<int> a(1001), b(1001);
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2;
        ul[y1][x1]++;
        ur[y1][x2]++;
        dl[y2][x1]++;
        dr[y2][x2]++;
    }
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            a[j] += ul[i][j];
            a[j] -= dl[i][j];
            cnt += a[j];
            b[j] -= ur[i][j];
            b[j] += dr[i][j];
            cnt += b[j];
            c += (cnt == k);
        }
    }
    cout << c;
    return 0;
}