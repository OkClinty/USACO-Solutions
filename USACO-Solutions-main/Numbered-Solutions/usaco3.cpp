#include <bits/stdc++.h>
using namespace std;

int arr[] = {'0', '0', '0', '1', '1', '0', '1', '1'};

void solve() {
    int n, m;
    string x;
    char y, num = '2';
    bool loob, booloob;
    cin >> n >> m;
    vector<pair<string, char>> v(m);
    vector<int> list;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < 8; b += 2) {
            loob = true;
            booloob = false;
            for (int c = 0; c < m; c++) {
                if (v[c].second == 'X') {
                    continue;
                } else if (v[c].first[a] == arr[b] && v[c].second != arr[b + 1]) {
                    booloob = true;
                    loob = false;
                    break;
                } else if (v[c].first[a] == arr[b]) {
                    list.push_back(c);
                }
                booloob = true;
            }
            if (!booloob) {
                break;
            } if (loob) {
                for (int i = 0; i < list.size(); i++) {
                    v[list[i]].second = 'X';
                }
                break;
            }
            list.clear();
        }
    }
    for (int a = n; a >= 0; a--) {
        for (int b = 0; b < 8; b += 2) {
            loob = true;
            booloob = false;
            for (int c = 0; c < m; c++) {
                if (v[c].second == 'X') {
                    continue;
                } else if (v[c].first[a] == arr[b] && v[c].second != arr[b + 1]) {
                    booloob = true;
                    loob = false;
                    break;
                } else if (v[c].first[a] == arr[b]) {
                    list.push_back(c);
                }
                booloob = true;
            }
            if (!booloob) {
                break;
            } if (loob) {
                for (int i = 0; i < list.size(); i++) {
                    v[list[i]].second = 'X';
                }
                break;
            }
            list.clear();
        }
    }
    for (int a = 0; a < n; a++) {
        for (int b = 0; b < 8; b += 2) {
            loob = true;
            booloob = false;
            for (int c = 0; c < m; c++) {
                if (v[c].second == 'X') {
                    continue;
                } else if (v[c].first[a] == arr[b] && v[c].second != arr[b + 1]) {
                    booloob = true;
                    loob = false;
                    break;
                } else if (v[c].first[a] == arr[b]) {
                    list.push_back(c);
                }
                booloob = true;
            }
            if (!booloob) {
                break;
            } if (loob) {
                for (int i = 0; i < list.size(); i++) {
                    v[list[i]].second = 'X';
                }
                break;
            }
            list.clear();
        }
    }
    for (int a = n; a >= 0; a--) {
        for (int b = 0; b < 8; b += 2) {
            loob = true;
            booloob = false;
            for (int c = 0; c < m; c++) {
                if (v[c].second == 'X') {
                    continue;
                } else if (v[c].first[a] == arr[b] && v[c].second != arr[b + 1]) {
                    booloob = true;
                    loob = false;
                    break;
                } else if (v[c].first[a] == arr[b]) {
                    list.push_back(c);
                }
                booloob = true;
            }
            if (!booloob) {
                break;
            } if (loob) {
                for (int i = 0; i < list.size(); i++) {
                    v[list[i]].second = 'X';
                }
                break;
            }
            list.clear();
        }
    }
    booloob = false;
    for (int i = 0; i < m; i++) {
        if (num != '2' && v[i].second != 'X' && v[i].second != num) {
            booloob = true;
        }
        if (v[i].second != 'X' && booloob) {
            cout << "LIE\n";
            return;
        } else if (v[i].second != 'X' && num == '2') {
            num = v[i].second;
        }
    }
    cout << "OK\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}