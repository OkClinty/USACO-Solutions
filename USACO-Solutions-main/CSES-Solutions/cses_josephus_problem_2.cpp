#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, p = 0, c = 0;
    cin >> n >> k;
    ordered_set st;
    ordered_set::iterator it;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    while (c < n) {
        p += k;
        p %= st.size();
        it = st.find_by_order(p);
        cout << *it << " ";
        st.erase(it);
        c++;
    }
    return 0;
}