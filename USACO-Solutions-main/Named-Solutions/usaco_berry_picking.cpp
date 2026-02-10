#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("berries.out");
    ifstream cin ("berries.in");
    int n, k, m = 0, c, p;
    cin >> n >> k;
    vector<int> v(n), u;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= 1000; i++) {
        u = v;
        ms.clear();
        for (int j = 0; j < n; j++) {
            if (u[j] >= i) {
                u[j] -= i;
                ms.insert(i);
                j--;
            }
            if (ms.size() == k) {
                break;
            }
        }
        sort(u.begin(), u.end(), greater<int>());
        p = 0;
        while (p < n && ms.size() < k) {
            ms.insert(u[p]);
            p++;
        }
        while (ms.size() < k) {
            ms.insert(0);
        }
        c = 0;
        p = k / 2;
        auto it = ms.begin();
        while (p--) {
            c += *it;
            it++;
        }
        m = max(m, c);
    }
    cout << m;
    return 0;
}