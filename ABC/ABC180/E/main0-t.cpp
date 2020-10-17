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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    cin >> n;
    vector<pair<int, pii>> zxy(n);
    rep(i, n) cin >> zxy[i].second.first >> zxy[i].second.second >> zxy[i].first;
    VSORT(zxy);
    ll ans = INF2;
    if (n <= 2) {
        ll val = 0;
        val += abs(zxy[1].second.first-zxy[0].second.first);
        val += abs(zxy[1].second.second-zxy[0].second.second);
        val *= 2;
        val += abs(zxy[1].first-zxy[0].first);
        ans = val;
    }
    else {
        rep(i, (1<<(n-2))) {
            ll val = 0;
            vi f, b;
            rep(j, (n-2)) {
                if ((i>>j)&1) f.pb(j+1);
                else b.pb(j+1);
            }
            reverse(all(b));
            rep(j, sz(f)) {
                if (j==0) {
                    val += abs(zxy[f[j]].second.first-zxy[0].second.first);
                    val += abs(zxy[f[j]].second.second-zxy[0].second.second);
                    val += zxy[f[j]].first - zxy[0].first;
                }
                else {
                    val += abs(zxy[f[j]].second.first-zxy[f[j-1]].second.first);
                    val += abs(zxy[f[j]].second.second-zxy[f[j-1]].second.second);
                    val += zxy[f[j]].first - zxy[f[j-1]].first;
                }
            }
            if (!f.empty()) {
                val += abs(zxy.back().second.first-zxy[f.back()].second.first);
                val += abs(zxy.back().second.second-zxy[f.back()].second.second);
                val += zxy.back().first - zxy[f.back()].first;
            }
            else {
                val += abs(zxy.back().second.first-zxy[0].second.first);
                val += abs(zxy.back().second.second-zxy[0].second.second);
                val += zxy.back().first - zxy[0].first;
            }
            rep(j, sz(b)) {
                if (j==0) {
                    val += abs(zxy[b[j]].second.first-zxy.back().second.first);
                    val += abs(zxy[b[j]].second.second-zxy.back().second.second);
                }
                else {
                    val += abs(zxy[b[j]].second.first-zxy[b[j-1]].second.first);
                    val += abs(zxy[b[j]].second.second-zxy[b[j-1]].second.second);
                }
            }
            if (!b.empty()) {
                val += abs(zxy[0].second.first-zxy[b.back()].second.first);
                val += abs(zxy[0].second.second-zxy[b.back()].second.second);
            }
            else {
                val += abs(zxy[0].second.first-zxy.back().second.first);
                val += abs(zxy[0].second.second-zxy.back().second.second);
            }
            ans = min(ans, val);
        }
    }
    cout << ans << endl;
    return 0;
}
