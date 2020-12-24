#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-10)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

map<ll, int> memo;
int search(ll i) {
    if (memo.find(i) != memo.end()) return memo[i];
    if (i==0 || i==2) return (memo[i] = 0);
    if (i == 1) return (memo[i] = 1);
    if (i == 3) return (memo[i] = 3);
    ll ni = (ll)(((sqrt(5.0)-1.0)/2.0)*i+EPS);
    int res1 = search(ni);
    if (res1 == 2) return (memo[i] = 3);
    ll mi = (ll)(ni * 2LL / (sqrt(5.0)-1.0) + EPS);
    if ((ni-mi)%2==1) {
        int res2 = search(mi-1LL);
        if (res2==2) return (memo[i] = 3);
        if (res1==3 && res2==3) return (memo[i] = 2);
        else if (res1==1 && res2==1) return (memo[i] = 0);
    }
    if (res1 == 1) return (memo[i] = 0);
    else if (res1 == 3) return (memo[i] = 2);
    else return (memo[i] = 1);
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        vll a(n);
        rep(i, n) cin >> a[i];
        vi cnt(4);
        rep(i, n) cnt[search(a[i])]++;
        bool ans = false;
        if (cnt[3] == 1) ans = true;
        else if (cnt[3] > 1) ans = false;
        else if (cnt[2] == n) ans = false;
        else if (cnt[2] == 0) {
            if (abs(cnt[1]-cnt[0])%2==1) ans = true;
            else ans = false;
        }
        else {
            if ((cnt[0]+cnt[1])%2==1) ans = true;
            else ans = false;
        }
        if (ans) cout << "Black" << endl;
        else cout << "White" << endl;
    }
    return 0;
}
