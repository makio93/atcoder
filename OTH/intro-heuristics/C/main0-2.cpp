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
    int d;
    cin >> d;
    vi c(26);
    rep(i, 26) cin >> c[i];
    vector<vi> s(d, vi(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vi t(d);
    rep(i, d) {
        cin >> t[i];
        t[i]--;
    }
    int m;
    cin >> m;
    vpii dq(m);
    rep(i, m) {
        cin >> dq[i].first >> dq[i].second;
        dq[i].first; dq[i].second--;
    }
    vi last(26);
    ll sum = 0;
    rep1(i, d) {
        sum += s[i-1][t[i-1]];
        last[t[i-1]] = i;
        rep(j, 26) sum -= c[j] * (i - last[j]);
    }
    rep(i, m) {
        int fq = t[dq[i].first-1], tq = dq[i].second;
        int td = dq[i].first;
        int fl = dq[i].first-1, fr = dq[i].first+1, tl = dq[i].first, tr = dq[i].first;
        while (fl > 0) {
            if (t[fl-1] == fq) break;
            --fl;
        }
        while (fr <= d) {
            if (t[fr-1] == fq) break;
            ++fr;
        }
        while (tl > 0) {
            if (t[tl-1] == tq) break;
            --tl;
        }
        while (tr <= d) {
            if (t[tr-1] == tq) break;
            ++tr;
        }
        sum -= s[td-1][fq];
        sum += (td-fl)*(td-fl-1)*c[fq]/2 + (fr-td)*(fr-td-1)*c[fq]/2;
        sum -= (fr-fl)*(fr-fl-1)*c[fq]/2;
        sum += s[td-1][tq];
        sum -= (td-tl)*(td-tl-1)*c[tq]/2 + (tr-td)*(tr-td-1)*c[tq]/2;
        sum += (tr-tl)*(tr-tl-1)*c[tq]/2;
        cout << sum << endl;
        t[td-1] = tq;
    }
    return 0;
}
