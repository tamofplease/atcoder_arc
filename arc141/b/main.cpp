// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

string toBinString(ll n) {
    string res = "";
    while (n > 0) {
        res.push_back((n % 2) + '0');
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ll n, m;
    cin >> n >> m;
    string n_bin = toBinString(n);
    string m_bin = toBinString(m);
    int m_bin_len = m_bin.length();
    if (n > m_bin_len) {
        cout << 0 << endl;
        return 0;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(m_bin_len + 1, 0));
    vector<ll> holder(m_bin_len + 1, 0);
    ll tmp = 1;
    const int MOD = 998244353;
    Rep(i, m_bin_len - 1) {
        holder[i] = tmp;
        tmp *= 2;
        tmp %= MOD;
        holder[i] %= MOD;
    }
    m %= MOD;
    holder[m_bin_len] = (m - tmp + 1 + MOD) % MOD;
    rep(i, m_bin_len + 1) { dp[0][i] = 1; }

    Rep(i, n) {
        Rep(j, m_bin_len) {
            dp[i][j] = dp[i - 1][j - 1] * holder[j];
            dp[i][j] %= MOD;
        }
        Rep(j, m_bin_len - 1) {
            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= MOD;
        }
    }

    cout << dp[n][m_bin_len] % MOD << endl;

    return 0;
}
