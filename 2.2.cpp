#include <bits/stdc++.h>
using namespace std;

string build(int n) {
    string res;
    res.reserve(5 * n);
    for (int i = 0; i < n; i++) res += "edgnb";
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        int k;
        cin >> s >> k;
        string p = build(k);
        int len = p.size(), cnt = 0;
        for (int j = 0; j + len <= s.size(); j++) {
            if (s.compare(j, len, p) == 0) cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}