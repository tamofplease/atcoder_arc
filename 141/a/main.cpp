// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

// n を　num分割する
vector<string> divd(string s, ll num) {
    vector<string> res;
    ll tmp = 0;
    ll n = s.length();
    rep(i, num) {
        res.push_back(s.substr(tmp, n / num));
        tmp += n / num;
    }
    return res;
}

/// oneLen文字のcurをdiv 回数繰り返す。
ll calcAns(ll div, ll oneLen, ll cur) {
    ll border = 1;
    ll res = 0;
    rep(i, div) {
        res += cur * border;
        rep(j, oneLen) {
            border *= 10;
        }
    }
    return res;
}

ll calcDefault(string s) {
    ll n = s.length();
    ll res = 9;
    rep(i, n-2) {
        res *= 10;
        res += 9;
    }
    return res;
}

int  main() {
    ll t;
    cin >> t;
    rep(i, t) {
        string s;
        cin >> s;
        ll n = s.length();
        ll sn = stol(s);
        ll ans = calcDefault(s);
        vector<ll> divisor;
        for (ll i = 2 ; i <= n ; i++) {
            if (n % i == 0) {
                divisor.push_back(i);
            }
        }
        /// div 分割する。
        for (ll div : divisor) {
            /// 一文字あたりのながさ
            ll repNum = n / div;
            vector<string> res = divd(s, div);
            ll border = stol(res[0]);
            bool flag = false;
            ll calcAns2 = calcAns(div, repNum, border);
            if (sn >= calcAns2) {
                ans = max(calcAns2, ans);
            } else {
                ans = max(ans, calcAns(div, repNum, border-1));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
