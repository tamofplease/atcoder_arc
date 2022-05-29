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
    vector<int> a(n);
    vector<int> ve(n-k, 0);
    rep(i, n) {
        cin >> a[i];
        if (i == k) {
            ve[i-k] = a[i];
        }
        if (i > k) {
            ve[i-k] = max(a[i], ve[i-k-1]);
        }
    }
/// 0 1 2 3 
/// 2 1 1 2
    int ans = 4000001;
    for (int i = k-1 ; i >= 0 ; i--) {
        int border = a[i];
        auto it = upper_bound(ve.begin(), ve.end(), border);
        if (it == ve.end()) {
            continue;
        }
        /// (how far the border is from k) + (how far is target)
        ans = min(ans, k - i + static_cast<int>(it - ve.begin()));
    }
    if (ans == 4000001)
        ans = -1;
    cout << ans << endl;
    return 0;
}
