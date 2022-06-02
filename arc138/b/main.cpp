// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) { cin >> a[i]; }
    // if true: consider 1 as 0; if not 1 as 1
    bool flipped = false;
    int front = 0, tail = n - 1;
    int prev_front = 0, prev_tail = n - 1;
    while (front <= tail) {
        prev_front = front;
        prev_tail = tail;
        while (front <= tail) {
            if (a[tail] == flipped) {
                tail--;
            } else {
                break;
            }
        }
        if (a[front] == flipped) {
            front++;
            flipped = !flipped;
        }
        if (prev_front == front && prev_tail == tail) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
