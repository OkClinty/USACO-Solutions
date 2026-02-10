#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("photo.out");
    ifstream cin ("photo.in");
    int n, p, c;
    bool b;
    cin >> n;
    vector<int> v(n - 1), arr;
    set<int> s;
    for (int i = 0; i < n - 1; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        p = 0;
        c = i;
        b = true;
        s.insert(i);
        arr.push_back(i);
        while (p < n - 1) {
            c = v[p] - c;
            if (s.find(c) != s.end() || c < 1 || c > n) {
                b = false;
                break;
            }
            s.insert(c);
            arr.push_back(c);
            p++;
        }
        if (b) {
            break;
        }
        arr.clear();
        s.clear();
    }
    cout << arr[0];
    for (int i = 1; i < n; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
    return 0;
}