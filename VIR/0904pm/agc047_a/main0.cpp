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
    vector<pair<ll, int>> a(n);
    rep(i, n) {
        string s;
        cin >> s;
        bool point = false;
        rep(i, sz(s)) {
            if (s[i] == '.') {
                point = true;
                a[i].second = sz(s) - i - 1;
                a[i].first = stoll(s.substr(0, i)) * a[i].second + stoll(s.substr(i+1, a[i].second));
                break;
            }
        }
        if (!point) {
            a[i].first = stoll(s);
            a[i].second = 0;
        }
    }
    vpii prime(n);
    rep(i, n) {
        ll num = a[i].first;
        while (num%2==0 && num>0) {
            num /= 2;
            prime[i].first++;
        }
        while (num%5==0 && num>0) {
            num /= 5;
            prime[i].second++;
        }
        prime[i].first -= a[i].second - 10;
        prime[i].second -= a[i].second - 10;
        //if (prime[i].first<0 || prime[i].second<0) cout << "error" << endl;
    }
    vector<vi> cnt(61, vi(61));
    vector<vll> csum(61, vll(61));
    rep(i, n) cnt[prime[i].first][prime[i].second]++;
    repr(i, 60) repr(j, 60) {
        csum[i][j] = csum[i+1][j] + csum[i][j+1] - csum[i+1][j+1] + cnt[i][j];
    }
    ll ans = 0;
    for (int i=0; i<=60; ++i) for (int j=0; j<=60; ++j) {
        int nf = i-10, ns = j-10;
        if (nf>=0 && ns>=0) continue;
        int ti = -nf + 10, tj = -ns + 10;
        ans += cnt[i][j] * csum[max(0,ti)][max(0,tj)] / 2;
    }
    ans /= 2;
    ans += csum[10][10] * (csum[10][10] - 1) / 2;
    cout << ans << endl;
    return 0;
}
