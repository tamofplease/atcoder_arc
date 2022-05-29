// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

const int mod = 998244353;

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

string toBinary(ll n) {
    string r;
    while (n != 0) {
        r = (n % 2 == 0 ? "0" : "1") + r;
        n /= 2;
    }
    return r;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string nBin = toBinary(m);
    int nBinLen = nBin.length();
    if (nBinLen < n) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> dp(nBinLen + 1, 0);
    dp[0] = 0;
    ll tmp = 1;

    Rep(i, nBinLen-1) {
        dp[i] = tmp % mod;
        tmp *= 2;
        tmp %= mod;
    }
    dp[nBinLen] = (tmp - (m - 1)) % mod;
    for (int n : dp) {
        cout << n << " " << endl;
    }
    rep(i, nBinLen) {
        dp[i+1] += dp[i];
    }

    ll ans = 0;

    return 0;
}
