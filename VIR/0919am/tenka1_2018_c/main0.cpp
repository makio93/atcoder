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
    int n;
    cin >> n;
    vll a(n), b;
    rep(i, n) cin >> a[i];
    b = a;
    VSORT(a);
    RSORT(b);
    ll ans = 0;
    if (n%2==0) {
        ll sum = 0;
        for (int i=0; i<n/2-1; ++i) {
            sum += llabs(b[i]-a[i]) + llabs(b[i+1]-a[i]);
        }
        sum += llabs(b[n/2-1]-a[n/2-1]);
        ans = max(ans, sum);
        sum = 0;
        for (int i=0; i<n/2-1; ++i) {
            sum += llabs(a[i]-b[i]) + llabs(a[i+1]-b[i]);
        }
        sum += llabs(a[n/2-1]-b[n/2-1]);
        ans = max(ans, sum);
    }
    else {
        ll sum = 0;
        for (int i=0; i<n/2; ++i) {
            sum += llabs(b[i]-a[i]) + llabs(b[i+1]-a[i]);
        }
        ans = max(ans, sum);
        sum = 0;
        for (int i=0; i<n/2; ++i) {
            sum += llabs(a[i]-b[i]) + llabs(a[i+1]-b[i]);
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
