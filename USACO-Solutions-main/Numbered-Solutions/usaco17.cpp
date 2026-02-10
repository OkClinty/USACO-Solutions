#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("highcard.out");
    ifstream fin ("highcard.in");
    int n, p = 0, pp, t = 0;
    fin >> n;
    vector<int> v(n), c(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n * 2; i++) {
        if (!binary_search(v.begin(), v.end(), i)) {
            c[p] = i;
            p++;
        }
    }
    pp = p = n - 1;
    while (p >= 0) {
        if (v[p] < c[pp]) {
            t++;
            pp--;
        }
        p--;
    }
    fout << t;
    return 0;
}