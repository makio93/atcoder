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
    int h, w, k;
    cin >> h >> w >> k;
    vs s(h);
    rep(i, h) cin >> s[i];
    vector<vi> a(h, vi(w));
    int num = 1;
    rep(i, h) {
        int cnt = count(all(s[i]), '#'), p = 0;
        if (cnt > 0) {
            rep(j, cnt) {
                while (s[i][p]!='#') {
                    a[i][p] = num;
                    ++p;
                }
                a[i][p] = num;
                ++p;
                ++num;
            }
            while (p<w) {
                a[i][p] = num - 1;
                ++p;
            }
        }
    }
    rep1(i, h-1) {
        if (a[i][0] == 0) a[i] = a[i-1];
    }
    repr(i, h-1) if (a[i][0] == 0) a[i] = a[i+1];
    rep(i, h) rep(j, w) printf("%d%c", a[i][j], (j<w-1?' ':'\n'));
    return 0;
}
