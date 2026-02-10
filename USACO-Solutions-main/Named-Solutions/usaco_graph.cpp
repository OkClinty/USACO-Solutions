#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 2e5+5;
int pw[N], ipw[N], fa[N], sz[N];

vector<int> component[N];

using val = pair<int, int>; // (len, residue)

val operator + (const val& a, const val& b) {
  return {a.first+b.first, (1LL*pw[b.first]*a.second+b.second)%MOD};
}

val& operator += (val& a, const val& b) {
  a = a + b;
  return a;
}

val operator - (const val& a, const val& b) {
  return {a.first-b.first, 1LL*(a.second-b.second+MOD)*ipw[b.first]%MOD};
}

val lazy[N], res[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  pw[0] = ipw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = 10LL*pw[i-1]%MOD;
  //700000005 = 10^-1 mod 1e9+7
  for (int i = 1; i < N; i++) ipw[i] = 700000005LL*ipw[i-1]%MOD;

  iota(fa, fa+N, 0);
  fill(sz, sz+N, 1);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) component[i].emplace_back(i);
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int ru = fa[u];
    int rv = fa[v];

    if (ru != rv) {
      // ensure that u is part of the smaller component
      if(sz[ru] > sz[rv]) swap(u,v), swap(ru, rv);

      val du = make_pair(1, i) + res[u] + lazy[ru];
      val dv = make_pair(1, i) + res[v] + lazy[rv];
      lazy[rv] += du;
      for (int x: component[ru]) res[x] += lazy[ru] + dv - lazy[rv];

      for (int x: component[ru]) fa[x] = rv;
      sz[rv] += sz[ru];
      component[rv].insert(component[rv].end(), component[ru].begin(), component[ru].end());
    }
  }
  for (int i = 0; i < n; i++) res[i] += lazy[fa[i]];
  for (int i = 0; i < n; i++) cout << res[i].second << '\n';
}