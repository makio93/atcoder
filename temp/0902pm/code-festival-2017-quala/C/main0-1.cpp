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

const string YES = "Yes";
const string NO = "No";


int main(){
    int h, w;
    cin >> h >> w;
    vs a(h);
    rep(i, h) cin >> a[i];
    vi cnt(26);
    rep(i, h) rep(j, w) cnt[a[i][j]-'a']++;
    int hi = h-2, wi = w;
    while (hi+2>0 && wi>0) {
        RSORT(cnt);
        vi req;
        if (wi>0) {
            if (hi+2 > 1) {
                rep(i, wi/2) req.pb(4);
                if (wi%2!=0) req.pb(2);
            }
            else {
                rep(i, wi/2) req.pb(2);
                if (wi%2!=0) req.pb(1);
            }
        }
        if (hi>0) {
            if (wi > 1) {
                rep(i, hi/2) req.pb(4);
                if ((hi+2)%2!=0) req.pb(2);
            }
            else {
                rep(i, hi/2) req.pb(2);
                if ((hi+2)%2!=0) req.pb(1);
            }
        }
        RSORT(req);
        int j = 0;
        bool ok = false;
        rep(i, sz(cnt)) {
            while (j<sz(req) && cnt[i]>=req[j]) {
                cnt[i] -= req[j];
                ++j;
            }
            if (j>=sz(req)) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            while (j < sz(req)) {
                bool ok2 = false;
                rep(i, sz(cnt)) {
                    if (cnt[i]>=req[j]) {
                        cnt[i] -= req[j];
                        ok2 = true;
                        break;
                    }
                }
                if (!ok2) break;
                ++j;
                if (j==sz(req)) ok = true;
            }
            if (!ok) {
                cout << NO << endl;
                return 0;
            }
        }
        hi -= 2; wi -= 2;
    }
    cout << YES << endl;
    return 0;
}
