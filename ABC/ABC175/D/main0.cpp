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
    vi p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vll c(n);
    rep(i, n) cin >> c[i];
    vector<vll> sum(n);
    vector<vll> mx(n);
    vi roops(n);
    rep(i, n) {
        int v = i;
        sum[i].pb(0);
        mx[i].pb(-1e18);
        vector<int> visited(n, -1);
        visited[i] = 0;
        int j = 0;
        while (1) {
            v = p[v];
            ll val = sum[i].back();
            sum[i].pb(val+c[v]);
            ll mxval = max(mx[i].back(), sum[i].back());
            mx[i].pb(mxval);
            ++j;
            if (visited[v]!=-1) {
                roops[i] = j-visited[v];
                break;
            }
            visited[v] = j;
        }
    }
    ll ans = -1e18;
    rep(i, n) {
        int ri2 = roops[i];
        int ri = sz(sum[i])-1;
        int rj = sz(sum[i])-1 - ri2;
        ll mx2 = -1e18;
        for (int j=rj+1; j<sz(sum[i]); ++j) {
            mx[i][j] = max(sum[i][j]-sum[i][rj], (j==rj+1?((ll)-1e18):mx[i][j-1]));
        }
        if (k >= ri) {
            int md = rj + (k-rj)%ri2;
            if ((k-rj)%ri2==0) md = ri;
            if (sum[i].back()-sum[i][rj] <= 0) mx2 = max(mx2, max(mx[i].back()+sum[i][rj], mx[i][rj]));
            else if (mx[i][md]+sum[i].back()-sum[i][rj] > mx[i].back()) mx2 = max(mx2, (mx[i][md])+(sum[i].back()-sum[i][rj])*((k-rj)/ri2)+sum[i][rj]);
            else mx2 = max(mx2, mx[i].back()+sum[i][rj]+(sum[i].back()-sum[i][rj])*(((k-rj)/ri2)-1));
        }
        else mx2 = max(mx2, mx[i][k]+(k>rj?sum[i][rj]:0));
        ans = max(ans, mx2);
    }
    cout << ans << endl;
    return 0;
}
