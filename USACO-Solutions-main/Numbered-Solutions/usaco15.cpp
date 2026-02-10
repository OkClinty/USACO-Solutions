#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream fout ("berries.out");
    ifstream fin ("berries.in");    
    int n, k, c, m;
    fin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 1; i <= 1000; i++) {
        c = 0;
        for (int j = 0; j < n; j++) {
            c += v[j] / i;
            if (v[j] < i) {
                break;
            }
        }
        if (c < k) {
            break;  
        }
        m = (c * i) / 2;
    }
    fout << m;
    return 0;
}