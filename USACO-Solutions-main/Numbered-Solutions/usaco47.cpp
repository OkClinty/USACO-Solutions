#include <bits/stdc++.h>
using namespace std;

string s;

int count(int l, int r) {
    int arr[26], c = 0;
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }
    for (int i = l + 1; i < r; i++) {
        arr[s[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        c += (arr[i] == 1);
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ofstream cout ("circlecross.out");
    ifstream cin ("circlecross.in");
    int c = 0, l, r;
    cin >> s;
    bool seen[26];
    for (int i = 0; i < 26; i++) {
        seen[i] = false;
    }
    for (int i = 0; i < s.length(); i++) {
        if (!seen[s[i] - 'A']) {
            l = i;
            for (int j = i + 1; j < s.length(); j++) {
                if (s[j] == s[i]) {
                    r = j;
                    break;
                }
            }
            c += count(l, r);
            seen[s[i] - 'A'] = true;
        }
    }
    cout << c / 2 << "\n";
    return 0;
}