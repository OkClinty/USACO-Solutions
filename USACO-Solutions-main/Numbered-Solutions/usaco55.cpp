#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("lemonade.out");
    ifstream cin ("lemonade.in");
    int n, c = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        c += (v[i] >= i);
    }
    cout << c << endl;
    return 0;
}