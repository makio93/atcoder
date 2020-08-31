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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi sum(n+1);
    rep(i, n) {
        sum[max(0,i-a[i])]++;
        sum[min(n,i+a[i]+1)]--;
    }
    rep(h, k-1) {
        vi sum2(n+1);
        int val = sum[0];
        sum2[0]++; sum2[min(n,val+1)]--;
        bool full = (val==n);
        rep1(i, n-1) {
            val += sum[i];
            sum2[max(0,i-val)]++;
            sum2[min(n,i+val+1)]--;
            if (i<=n-1 && val!=n) full = false;
        }
        swap(sum, sum2);
        if (full) break;
    }
    vi ans(n);
    ans[0] = sum[0];
    rep1(i, n-1) ans[i] = ans[i-1] + sum[i];
    rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
