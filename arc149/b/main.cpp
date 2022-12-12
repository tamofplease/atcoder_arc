// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    rep(i, n) cin >> v[i].first;
    rep(i, n) cin >> v[i].second;
    sort(v.begin(), v.end(), [](const pair<int, int> &a, pair<int, int> &b) -> bool {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int ans = 1;
    vector<int> li;
    li.push_back(v[0].second);
    for (int i = 1; i < n; i++) {
        if (v[i - 1].first < v[i].first) ans++;
    }
    for (int i = 1; i < n; i++) {
        if (li.back() < v[i].second) {
            li.push_back(v[i].second);
            continue;
        }
        int idx = lower_bound(ALL(li), v[i].second) - li.begin();
        li[idx] = v[i].second;
    }
    cout << (ans + (int)li.size()) << endl;
    return 0;
}
