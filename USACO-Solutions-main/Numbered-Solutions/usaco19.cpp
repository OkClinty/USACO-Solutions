#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("planting.out");
    ifstream fin ("planting.in");
    int n, x, y, m = 0;
    fin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i < n; i++) {
        fin >> x >> y;
        v[x]++;
        v[y]++;
    } 
    for (int i = 1; i <= n; i++) {
        m = max(m, v[i]);
    }
    fout << m + 1;
    return 0;
}