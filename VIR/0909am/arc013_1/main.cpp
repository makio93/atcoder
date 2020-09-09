#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    vi a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    vi dir = b;
    VSORT(dir);
    int ans = 0;
    do {
        int cnt = 0;
        vi space(3), ord(3);
        space = a;
        rep(i, 3) ord[i] = i;
        do {
            int p = dir[ord[0]], q = dir[ord[1]], r = dir[ord[2]];
            if (p>space[0] || q>space[1] || r>space[2]) continue;
            cnt += (space[0] / p) * (space[1] / q) * (space[2] / r);
            space[0] %= p; space[1] %= q; space[2] %= r;
        } while (next_permutation(all(ord)));
        ans = max(ans, cnt);
    } while (next_permutation(all(dir)));
    cout << ans << endl;
    return 0;
}
