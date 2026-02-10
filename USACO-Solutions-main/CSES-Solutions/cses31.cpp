#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c = 0, m = 0, num, p = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (mp.find(num) != mp.end() && mp[num] >= p) {
            m = max(m, c);
            p = mp[num] + 1;
            c = i - p;
        }
        c++;
        mp[num] = i;
    }
    cout << max(c, m) << "\n";
    return 0;
}