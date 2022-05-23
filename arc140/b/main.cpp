// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int arc = 0;
    const string tg = "ARC";
    vector<int> arcBegin;
    rep(i, n) {
        if (i <= n - 2) {
            rep(j, 3) {
                if (s[i + j] != tg[j]) {
                    break;
                } else if (j == 2) {
                    arc++;
                    arcBegin.push_back(i);
                }
            }
        }
    }
    int aarcc = 0;
    for (int b : arcBegin) {
        int left = b - 1, right = b + 3;
        while (left >= 0 && right < n) {
            if (s[left] != 'A' || s[right] != 'C') {
                break;
            }
            left--;
            right++;
            aarcc++;
        }
    }
    int ans = 0;
    int i = 1;
    while (arc > 0 && aarcc > 0) {
        (i % 2 ? aarcc : arc)--;
        ans++;
        i++;
    }
    cout << ans + arc << endl;
    return 0;
}
