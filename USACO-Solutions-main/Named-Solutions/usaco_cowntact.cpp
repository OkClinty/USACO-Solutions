#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

vector<vector<int>> adj;
string infected;
vector<int> closest_not_infected;
int N;

vector<int> closest_ok;
int n, ans;

pair<int, int> comb(pair<int, int> a, pair<int, int> b) {
	if (a > b) swap(a, b);
	if (a.first == 0) return b;
	if (b.first == 0) return a;
	if (b.first == -1) return max(a, b);
	if (a.first == 1) return min(a, b);
	if (a.second + b.second > n) return a;
	return b;
}

pair<int, int> dfs(int x, int p) {
	pair<int, int> best{infected.at(x) == '1' ? -1 : 0, 0};
	for (int y : adj[x]) {
		if (y != p) {
			pair<int, int> d = dfs(y, x);
			if (d.first != 0) d.second++;
			best = comb(best, d);
		}
    }
	if (best.first == -1) {
		if (p == -1 || best.second + 1 + closest_ok[p] > n) {
			ans++;
			best = {1, closest_ok[x]};
		}
	}
	return best;
}

vector<int> multi_bfs(const vector<int> &sources) {
	vector<int> ret(N, N + 1);
	queue<int> q;
	for (int i : sources) {
		ret[i] = 0;
		q.push(i);
	}
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (int y : adj[x]) {
			if (ret[x] + 1 < ret[y]) {
				ret[y] = ret[x] + 1;
				q.push(y);
			}
        }
	}
	return ret;
}

int query() {
	vector<int> origins;
    for (int i = 0; i < N; i++) {
        if (closest_not_infected[i] > n) {
            origins.push_back(i);
        }
    }
	closest_ok = multi_bfs(origins);
    for (int i = 0; i < N; i++) {
        if (infected[i] == '1' && closest_ok[i] > n) {
            return -1;
        }
    }
	ans = 0;
	dfs(0, -1);
	return ans;
}

int main() {
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> infected;
	adj.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
	}
	vector<int> sources;
    for (int i = 0; i < N; i++) {
        if (infected[i] == '0') {
            sources.push_back(i);
        }
    }
	closest_not_infected = multi_bfs(sources);
	int Q;
	cin >> Q;
	while (Q--) {
		cin >> n;
		cout << query() << "\n";
	}
}