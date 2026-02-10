#include <bits/stdc++.h>
using namespace std;

vector<int> v;

bool process(int k, int m, int c) {
    int i = 0;
    while (i < v.size() && m > 0) {
        int num = distance(v.begin(), upper_bound(v.begin(), v.end(), v[i] + k));
        m--;
        i = min(i + c, num);
    }
    return (i >= v.size());
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("convention.out");
    ifstream cin ("convention.in");
    int n, m, c, l = 0, r = 1e9, md;
    cin >> n >> m >> c;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    while (l < r) {
        md = (l + r) / 2;
        if (process(md, m, c)) {
            r = md;
        } else {
            l = md + 1;
        }
    }
    cout << l;
    return 0;
}