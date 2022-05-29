// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t
string getBin(ll decimal) {
    string binary = "";
    int remainder;
    while (decimal != 0) {
        remainder = decimal % 2;
        binary.push_back(remainder + '0');
        decimal = decimal / 2;
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    rep(i, n) {
        int t;
        cin >> t;
        ll pt = 1LL << t;
        ans = (ans / pt + 1) * pt;
        if (ans % (pt * 2) == 0) {
            ans += pt;
        }
    }
    cout << ans << endl;

    return 0;
}
