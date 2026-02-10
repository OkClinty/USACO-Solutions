#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, num;
    cin >> n;
    multiset<int> s;
    while (n--) {
        cin >> num;
        multiset<int>::iterator it = s.upper_bound(num);
        if (it != s.end()) {
            s.erase(it);
        }
        s.insert(num);
    }
    cout << s.size() << "\n";
    return 0;
}