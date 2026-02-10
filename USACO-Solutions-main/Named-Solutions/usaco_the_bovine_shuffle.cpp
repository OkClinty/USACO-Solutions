#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ifstream cin ("shuffle.in");
    ofstream cout ("shuffle.out");
int n, r = 0, p, c, num;
    cin >> n;
    vector<int> a(n + 1);
    set<int> s;
    vector<bool> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            num = i;
            while (!v[num] && s.find(num) == s.end()) {
                v[num] = true;
                s.insert(num);
                num = a[num];
            }
            if (s.find(num) != s.end()) {
                p = num;
                c = 0;
                do {
                    c++;
                    num = a[num];
                } while (num != p);  
                r += c;
            }
            s.clear();
        }
    }
    cout << r << "\n";
    return 0;
}