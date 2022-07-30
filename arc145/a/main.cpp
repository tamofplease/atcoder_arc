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
    int n;
    string s;
    cin >> n >> s;
    int front = 0;
    int back = n - 1;
    if (n == 2) {
        s[0] == s[1] ? puts("Yes") : puts("No");
        return 0;
    }
    while (front <= back && s[front] != 'B' && s[back] != 'A') {
        if (s[front] == s[back]) {
            front++;
            back--;
        } else {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
