#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> p, s;

int find_p(int n) {
    if (n == p[n]) {
        return n;
    }
    p[n] = find_p(p[n]);
    return p[n];
}

pair<int, int> union_s(int a, int b, int num, int size) {
    a = find_p(a);
    b = find_p(b);
    if (a != b) {
        num--;
        if (s[a] > s[b]) {
            swap(a, b);
        }
        p[a] = b;
        s[b] += s[a];
        size = max(size, s[b]);
    }
    return {num, size};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, a, b, num, size = 1;
    cin >> n >> m;
    p.resize(n + 1);
    s.resize(n + 1, 1);
    pair<int, int> pr;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    num = n;
    while (m--) {
        cin >> a >> b;
        pr = union_s(a, b, num, size);
        num = pr.first;
        size = pr.second;
        cout << num << " " << size << "\n";
    }
    return 0;
}