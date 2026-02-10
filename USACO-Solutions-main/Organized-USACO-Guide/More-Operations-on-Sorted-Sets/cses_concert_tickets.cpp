#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, num;
    cin >> n >> m;
    multiset<int> ms;
    while (n--) {
        cin >> num;
        ms.insert(num * -1);
    }
    while (m--) {
        cin >> num;
        multiset<int>::iterator it = ms.lower_bound(num * -1);
        if (it == ms.end()) {
            cout << "-1\n";
        } else {
            cout << *it * -1 << "\n";
            ms.erase(it);
        }
    }
    return 0;
}