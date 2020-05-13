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

const int rn = 1000000;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vpii ab(m);
    rep(i, m) cin >> ab[i].first >> ab[i].second;
    vi t(n);
    rep(i, n) t[i] = i;
    int cnt = 0;
    srand((unsigned)time(NULL));
    rep(i, rn) {
        vi t2 = t;
        rep(j, k) {
            int aj = rand() % n;
            int bj = (aj + rand() % (n - 1) + 1) % n;
            swap(t2[aj], t2[bj]);
        }
        bool ok = true;
        rep(j, m) {
            int ap, bp;
            rep(h, n) {
                if (t2[h] != ab[j].first) continue;
                ap = h;
                break;
            }
            rep(h, n) {
                if (t2[h] != ab[j].second) continue;
                bp = h;
                break;
            }
            if (abs(bp-ap)==1||abs(bp-ap)==n-1) ok = false;
        }
        if (ok) ++cnt;
    }
    printf("%.10f\n", (double)cnt / rn);
    return 0;
}
