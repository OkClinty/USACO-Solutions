#include <bits/stdc++.h>
using namespace std;

string s;
set<int> st;
multiset<int> ms;

void solve(int x) {
    if (x != 0 && x != s.size()) {
        auto it = st.find(x);
        if (it != st.end()) {
            ms.erase(ms.find(*next(it) - x));
            ms.erase(ms.find(x - *prev(it)));
            ms.insert(*next(it) - *prev(it));
            st.erase(it);
        } else {
            it = st.insert(x).first;
            ms.erase(ms.find(*next(it) - *prev(it)));
            ms.insert(*next(it) - x);
            ms.insert(x - *prev(it));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m, x;
    cin >> s >> m;
    st.insert(0);
    st.insert(s.size());
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
            st.insert(i + 1);
        }
    }
    for (auto it = st.begin(); next(it) != st.end(); it++) {
        ms.insert(*next(it) - *it);
    }
    while (m--) {
        cin >> x;
        solve(x - 1);
        solve(x);
        cout << *ms.rbegin() << " ";
    }
    return 0;
}