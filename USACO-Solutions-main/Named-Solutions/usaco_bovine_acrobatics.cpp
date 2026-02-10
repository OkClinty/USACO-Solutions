#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k, c;
	long long r = 0;
	cin >> n >> m >> k;
	vector<pair<int, int>> v(n);
	set<pair<int, int>> s;
	s.insert({-k, m});
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		auto end = s.upper_bound({v[i].first - k, INT_MAX});
		c = v[i].second;
		while ((*end).first != (*(s.begin())).first) {
		    auto it = s.begin();
			if ((*it).second == c) {
				s.erase(it);
				c = 0;
				break;
			} else if ((*it).second > c) {
				s.insert({(*it).first, (*it).second - c});
				s.erase(it);
				c = 0;
				break;
			} else {
				c -= (*it).second;
				s.erase(it);
			}
		}
		r += v[i].second - c;
		if (c != v[i].second) {
			s.insert({v[i].first, v[i].second - c});
		}
	}
	cout << r;
	return 0;
}