#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    long long t = 0;
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, l1, l2, l3, l4, l5;
    string s;
    cin >> s;
    for (long long i = 0; i < s.length(); i++) {
        if (s[i] == 'b' && s4 > 0 && s5 == 0) {
            l5 = i;
            s5++;
        } else if (s4 > 0 && ((s[i] == 'e' && s5 == 1) || (s[i] == 's' && s5 == 2) || (s[i] == 's' && s5 == 3) || (s[i] == 'i' && s5 == 4))) {
            s5++;
        } 
        if (s[i] == 'b' && s3 > 0 && s4 == 0) {
            l4 = i;
            s4++;
        } else if (s3 > 0 && ((s[i] == 'e' && s4 == 1) || (s[i] == 's' && s4 == 2) || (s[i] == 's' && s4 == 3) || (s[i] == 'i' && s4 == 4))) {
            s4++;
        } 
        if (s[i] == 'b' && s2 > 0 && s3 == 0) {
            l3 = i;
            s3++;
        } else if (s2 > 0 && ((s[i] == 'e' && s3 == 1) || (s[i] == 's' && s3 == 2) || (s[i] == 's' && s3 == 3) || (s[i] == 'i' && s3 == 4))) {
            s3++;
        } 
        if (s[i] == 'b' && s1 > 0 && s2 == 0) {
            l2 = i;
            s2++;
        } else if (s1 > 0 && ((s[i] == 'e' && s2 == 1) || (s[i] == 's' && s2 == 2) || (s[i] == 's' && s2 == 3) || (s[i] == 'i' && s2 == 4))) {
            s2++;
        } 
        if (s[i] == 'b' && s1 == 0) {
            l1 = i;
            s1++;
        } else if ((s[i] == 'e' && s1 == 1) || (s[i] == 's' && s1 == 2) || (s[i] == 's' && s1 == 3) || (s[i] == 'i' && s1 == 4)) {
            s1++;
        } else if (s[i] == 'e' && s1 == 5) {
            s1 = s2;
            s2 = s3;
            s3 = s4;
            s4 = s5;
            s5 = 0;
            t += (long long) 1ll * (l1 + 1) * (s.length() - i);
            l1 = l2;
            l2 = l3;
            l3 = l4;
            l4 = l5;
        } 
        if (s1 == s2) {
            l1 = l2;
            l2 = l3;
            l3 = l4;
            l4 = l5;
            s2 = s3;
            s3 = s4;
            s4 = s5;
            s5 = 0;
        } else if (s2 == s3) {
            l2 = l3;
            l3 = l4;
            l4 = l5;
            s3 = s4;
            s4 = s5;
            s5 = 0;
        } else if (s3 == s4) {
            l3 = l4;
            l4 = l5;
            s4 = s5;
            s5 = 0;
        } else if (s4 == s5) {
            l4 = l5;
            s5 = 0;
        }
    }
    cout << t << "\n";
    return 0;
}