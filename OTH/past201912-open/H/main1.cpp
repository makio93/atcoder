#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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
    vi c(n);
    rep(i, n) cin >> c[i];
    int amin = INF, omin = INF;
    rep(i, n) {
        if (i%2==0) omin = min(omin, c[i]);
        amin = min(amin, c[i]);
    }
    int an = 0, on = 0;
    ll ans = 0;
    int q;
    cin >> q;
    rep(i, q) {
        int sn;
        cin >> sn;
        if (sn==1) {
            int x, a;
            cin >> x >> a;
            --x;
            int sub = x%2==0?on:an;
            if (c[x]-sub < a) continue;
            c[x] -= a;
            ans += a;
            amin = min(amin, c[x]-sub);
            if (x%2==0) omin = min(omin, c[x]-sub); 
        }
        else if (sn==2) {
            int a;
            cin >> a;
            if (omin < a) continue;
            on += a;
            omin -= a;
            ans += a * ((n+1) / 2);
        }
        else {
            int a;
            cin >> a;
            if (amin<a || omin<a) continue;
            an += a;
            amin -= a;
            on += a;
            omin -= a;
            ans += a * n;
        }
    }
    cout << ans << endl;
    return 0;
}
