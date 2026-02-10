    #include <bits/stdc++.h>
using namespace std;

long long solve(long long x, long long n, long long k, long long m) {
    long long c = 0, g = 0, t = 0;
    while ((n - g) / x > m && t < sqrt(n)) {
        c += ((n - g) / x) - k;
        g += (n - g) / x;
        t++;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("loan.out");
    ifstream cin ("loan.in");    
    long long n, k, m, l = 1, r = 1e12, mid;
    cin >> n >> k >> m;
    while (l < r) {
        mid = (l + r - 1) / 2;
        if (solve(mid, n, k, m) >= n - k * m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}