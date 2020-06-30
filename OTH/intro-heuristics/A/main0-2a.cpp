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
    int ti = clock();
    int d;
    cin >> d;
    vi c(26);
    rep(i, 26) cin >> c[i];
    vector<vi> s(d, vi(26));
    rep(i, d) rep(j, 26) cin >> s[i][j];
    vi last(26), t(d);
    ll sum = 0;
    rep1(i, d) {
        ll cm = 0;
        rep(j, 26) cm += c[j] * (i - last[j]);
        pii m(-INF, -1);
        rep(j, 26) {
            ll sat = s[i-1][j] - cm + c[j] * (i - last[j]);
            m = max(m, {sat, j});
        }
        sum += m.first;
        last[m.second] = i;
        t[i-1] = m.second;
        //cout << (m.second + 1) << endl;
    }
    srand((unsigned)time(NULL));
    while (clock()-ti < CLOCKS_PER_SEC*195/100) {
        int dr = rand() % d + 1, qr = rand() % 26;
        int fq = t[dr-1], tq = qr;
        int td = dr;
        int fl = dr-1, fr = dr+1, tl = dr, tr = dr;
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
        ll nsum = sum;
        nsum -= s[td-1][fq];
        nsum += (td-fl)*(td-fl-1)*c[fq]/2 + (fr-td)*(fr-td-1)*c[fq]/2;
        nsum -= (fr-fl)*(fr-fl-1)*c[fq]/2;
        nsum += s[td-1][tq];
        nsum -= (td-tl)*(td-tl-1)*c[tq]/2 + (tr-td)*(tr-td-1)*c[tq]/2;
        nsum += (tr-tl)*(tr-tl-1)*c[tq]/2;
        //cout << sum << endl;
        if (nsum >= sum*1.02) t[td-1] = tq;
    }
    rep(i, d) cout << (t[i] + 1) << endl;
    return 0;
}
