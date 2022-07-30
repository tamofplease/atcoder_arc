// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    if (A <= B) {
        cout << max((ll)0, N - A + 1) << endl;
        return 0;
    }
    if (N < A) {
        cout << 0 << endl;
        return 0;
    }
    ll loop = N / A;
    ll rem = N % A;
    ll ans = min(rem + 1, B);
    ans += (loop - 1) * B;
    cout << ans << endl;

    return 0;
}
