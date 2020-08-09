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
    int n, l, t;
    cin >> n >> l >> t;
    vi x(n), w(n);
    rep(i, n) cin >> x[i] >> w[i];
    vector<vi> p(2);
    rep(i, n) {
        if (w[i] == 1) p[0].pb(i);
        else p[1].pb(i);
    }
    if (sz(p[0])==0||sz(p[1])==0) {
        if (sz(p[0])==0) t *= -1;
        rep(i, n) {
            int val = (x[i] + t) % l;
            cout << val << endl;
        }
    }
    else {
        double mt = INF, mb = INF;
        int xt = x[1], xb = x[n-1];
        for (int i=0; i<n; ++i) {
            double avg = ((ll)xt + x[i]) % l / 2.0;
            if (w[1]==w[i]) avg = INF;
            double avg2 = ((ll)xb + x[i]) % l / 2.0;
            if (w[n-1]==w[i]) avg2 = INF;
            double tt = ((avg-l/2.0>=0)?avg-l/2.0:avg);
            if (avg == INF) tt = INF;
            double tb = ((avg2-l/2.0>=0)?avg2-l/2.0:avg2);
            if (avg2 == INF) tb = INF;
            if ((avg!=INF&&avg2!=INF)&&avg2>avg) swap(avg2, avg);
            if (tt!=INF) mt = (mt==INF?tt:((tt<mt)?tt:mt));
            if (tb!=INF) mb = (mb==INF?tb:((tb>mb)?tb:mb));
        }
        vi y(n);
        rep(i, n) {
            if (w[i] == 1) y[i] = (x[i] + (t % l)) % l;
            else y[i] = (x[i] - (t % l) + l) % l;
        }
        double tar = mb;
        if (tar<0) tar += l;
        int r = lower_bound(all(y), tar) - y.begin();
        if (r == n) r = 0;
        rep(i, n) cout << (y[(r+i)%n]) << endl;
    }
    return 0;
}
