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

/*
int dfs(vi a) {
    vi b2 = b;
    bool ok = false;
    do {
        bool ok2 = true;
        rep(i, 3) if (a[i] < b2[i]) ok2 = false;
        if (ok2) ok = true;
    } while (next_permutation(all(b2)));
    if (!ok) return 0;
    b2 = b;
    do {

    } while (next_permutation(all(b2)))
}
*/

int main(){
    vi a(3), b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    VSORT(b);
    int ans = 0;
    do {
        vi b2 = b, a2 = a;
        int cnt = 0;
        do {
            int cnt2 = 1;
            rep(i, 3) {
                cnt2 *= a2[i] / b2[i];
                a2[i] = a2[i] % b2[i];
            }
            cnt += cnt2;
        } while (next_permutation(all(b2)));
        ans = max(ans, cnt);
    } while (next_permutation(all(b)));
    cout << ans << endl;
    return 0;
}
