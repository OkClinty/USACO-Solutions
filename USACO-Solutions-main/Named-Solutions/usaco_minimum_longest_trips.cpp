#include <bits/stdc++.h>
using namespace std;

#define int long long

void euler(int num, stack<int> &s, vector<bool> &vs, vector<vector<int>> &vv) {
	if (!vs[num]) {
		vs[num] = true;
		for (int i : vv[num]) {
			euler(i, s, vs, vv);
		}
		s.push(num);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, a, b, c, num, cur;
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n);
	vector<vector<int>> vv(n);
	vector<pair<int, int>> r(n);
	vector<int> vvv;
	vector<bool> vs(n);
	stack<int> s;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--;
		b--;
		v[a].push_back({b, c});
		vv[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (v[i].size() == 0) {
			vvv.push_back(i);
		}
	}
	for (int i : vvv) {
		euler(i, s, vs, vv);
	}
	while (!s.empty()) {
		num = s.top();
		s.pop();
		cur = 0;
		for (auto p : v[num]) {
			if (r[num].first < r[p.first].first + 1 || (r[num].first == r[p.first].first + 1 && cur > p.second)) {
				cur = p.second;
				r[num] = {r[p.first].first + 1, cur + r[p.first].second};
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << r[i].first << " " << r[i].second << "\n";
	}
	return 0;
}