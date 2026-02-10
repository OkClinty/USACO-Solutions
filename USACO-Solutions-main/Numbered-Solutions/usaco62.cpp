#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int compute(int i, int s, int n) {
	if (n == 1) {
		return 0;
	} else if (i == 0) {
		return s - (v[0].second - v[0].first) + max(0, v[0].second - v[1].first);
	} else if (i == n - 1) {
		return s - (v[n - 1].second - v[n - 1].first) + max(0, v[n - 2].second - v[n - 1].first);
	} else {
		return s - (v[i].second - v[i].first) + max(0, v[i - 1].second - v[i].first) + max(0, v[i].second - v[i + 1].first);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	ofstream cout ("lifeguards.out");
    	ifstream cin ("lifeguards.in");
	int n, s, m = 0;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	s = v[0].second - v[0].first;
	for (int i = 1; i < n; i++) {
		s += v[i].second - v[i].first;
		if (v[i - 1].second > v[i].first) {
			s -= v[i - 1].second - v[i].first;
		}
	}
	for (int i = 0; i < n; i++) {
		m = max(m, compute(i, s, n));
	}
	cout << m;
	return 0;
}