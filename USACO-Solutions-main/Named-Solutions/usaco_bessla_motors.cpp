#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, c, r, k, a, b, l, cnt, seen;
	cin >> n >> m >> c >> r >> k;
	vector<vector<pair<int, int>>> v(n + 1);
	vector<int> res;
	vector<bool> vs(n + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	while (m--) {
		cin >> a >> b >> l;
		v[a].push_back({l, b});
		v[b].push_back({l, a});
	}
	if (c > 100) {
		for (int i = c + 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				vs[j] = false;
			}
			vs[i] = true;
			seen = 1;
			cnt = 0;
			while (!pq.empty()) {
				pq.pop();
			}
			for (auto p : v[i]) {
				if (p.first <= r) {
					pq.push(p);
				}
			}
			while (seen < n && cnt < k && pq.size() > 0) {
				auto p = pq.top();
				pq.pop();
				if (!vs[p.second]) {
					vs[p.second] = true;
					seen++;
					if (p.second <= c) {
						cnt++;
					}
					for (auto pr : v[p.second]) {
						if (pr.first + p.first <= r) {
							pq.push({pr.first + p.first, pr.second});
						}
					}
				}
			}
			if (cnt >= k) {
				res.push_back(i);
			}
		}
	} else {
		vector<int> vv(n + 1);
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j <= n; j++) {
				vs[j] = false;
			}
			vs[i] = true;
			seen = 1;
			cnt = 0;
			while (!pq.empty()) {
				pq.pop();
			}
			for (auto p : v[i]) {
				if (p.first <= r) {
					pq.push(p);
				}
			}
			while (seen < n && cnt < k && pq.size() > 0) {
				auto p = pq.top();
				pq.pop();
				if (!vs[p.second]) {
					vs[p.second] = true;
					seen++;
					if (p.second > c) {
						vv[p.second]++;
					}
					for (auto pr : v[p.second]) {
						if (pr.first + p.first <= r) {
							pq.push({pr.first + p.first, pr.second});
						}
					}
				}
			}
		}
		for (int i = c + 1; i <= n; i++) {
			if (vv[i] >= k) {
				res.push_back(i);
			}
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i : res) {
		cout << i << "\n";
	}
	return 0;
}