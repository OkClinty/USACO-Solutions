#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("cbarn.out");
    ifstream cin ("cbarn.in");
    long long cnt, mn = LLONG_MAX;
    int n, pos, mlt;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        mlt = 0;
        pos = i;
        while (mlt < n) {
            cnt += 1ll * mlt * v[pos];
            mlt++;
            pos++;
            pos %= n;
        }
        mn = min(mn, cnt);
    }
    cout << mn << "\n";
    return 0;
}