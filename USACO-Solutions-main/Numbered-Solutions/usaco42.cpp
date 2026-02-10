#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Airport {
    int lowest, layover;
    vector<tuple<int, int, int, bool>> flights;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, c, r, d, s;
    cin >> n >> m;
    vector<Airport> v(n + 1);
    stack<pair<pair<int, int>, Airport>> st;
    pair<pair<int, int>, Airport> a;
    while (m--) {
        cin >> c >> r >> d >> s;
        v[c].flights.push_back({r, d, s, false});
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i].layover;
        v[i].lowest = INT_MAX;
    }
    v[1].lowest = 0;
    for (auto f : v[1].flights) {
        if (get<2>(f) < v[get<1>(f)].lowest) {
            get<3>(f) = true;
            v[get<1>(f)].lowest = get<2>(f);
            st.push({{get<2>(f), get<1>(f)}, v[get<1>(f)]});
        }
    }
    while (!st.empty()) {
        a = st.top();
        st.pop();
        for (auto f : a.second.flights) {
            if (!get<3>(f) && a.first.first + v[a.first.second].layover <= get<0>(f) && get<2>(f) < v[get<1>(f)].lowest) {
                get<3>(f) = true;
                v[get<1>(f)].lowest = get<2>(f);
                st.push({{get<2>(f), get<1>(f)}, v[get<1>(f)]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].lowest == INT_MAX) {
            cout << "-1\n";
        } else {
            cout << v[i].lowest << "\n";
        }
    }
    return 0;
}