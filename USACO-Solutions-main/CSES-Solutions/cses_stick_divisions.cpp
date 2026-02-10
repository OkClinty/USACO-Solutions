#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x, n, num;
    long long r = 0;
    cin >> x >> n;
    multiset<long long> ms;
    while (n--) {
        cin >> num;
        ms.insert(num);
    }
    while (ms.size() > 1) {
        r += *ms.begin() + *next(ms.begin());
        ms.insert(*ms.begin() + *next(ms.begin()));
        ms.erase(ms.begin());
        ms.erase(ms.begin());
    }
    cout << r;
    return 0;
}