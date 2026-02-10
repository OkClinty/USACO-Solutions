#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x, n, num;
    cin >> x >> n;
    set<int> s;
    multiset<int> ms;
    s.insert(0);
    s.insert(x);
    ms.insert(x);
    while (n--) {
        cin >> num;
        set<int>::iterator it = s.lower_bound(num);
        ms.erase(ms.find(*it - *prev(it)));
        ms.insert(*it - num);
        ms.insert(num - *prev(it, 1));
        s.insert(num);
        cout << *prev(ms.end(), 1) << " ";
    }
    return 0;
}