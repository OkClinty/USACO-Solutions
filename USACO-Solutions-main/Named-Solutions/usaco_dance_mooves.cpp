#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, k, a, b, num;
	cin >> n >> k;
	vector<int> p(n), r(n, -1), v;
	vector<set<int>> s(n);
	set<int> st;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		s[i].insert(i);
	}
	while (k--) {
		cin >> a >> b;
		a--;
		b--;
		swap(p[a], p[b]);
		s[p[b]].insert(a);
		s[p[a]].insert(b);
	}
	for (int i = 0; i < n; i++) {
		if (r[i] == -1) {
			num = i;
			do {
				v.push_back(num);
				num = p[num];
			} while (num != i);
			for (int j : v) {
				for (auto it = s[j].begin(); it != s[j].end(); it++) {
					st.insert(*it);
				}
			}
			for (int j : v) {
				r[j] = st.size();
			}
			st.clear();
			v.clear();
		}
	}
	for (int i : r) {
		cout << i << "\n";
	}
	return 0;
}