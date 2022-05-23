// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    Rep(wordLength, n / 2) if (n % wordLength == 0) {
        int tmp = 0;
        rep(setNum, wordLength) {
            map<char, int> ma;
            int m = -1;
            rep(repNum, n / wordLength) {
                char tgt = s[setNum + repNum * wordLength];
                ma[tgt]++;
                m = max(m, ma[tgt]);
            }
            tmp += (n / wordLength) - m;
        }
        if (tmp <= k) {
            cout << wordLength << endl;
            return 0;
        }
    }
    cout << n << endl;
    return 0;
}
