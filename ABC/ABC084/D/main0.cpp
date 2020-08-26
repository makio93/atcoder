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

const int MAX = 1e5;

int main(){
    int q;
    cin >> q;
    vi l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    vi p(MAX+1, 1);
    p[0] = p[1] = 0;
    for (int i=2; i*i<=MAX; ++i) {
        if (p[i]==0) continue;
        for (int j=i*2; j<=MAX; j+=i) p[j] = 0;
    }
    vi a(MAX+1);
    rep1(i, MAX) if (p[i]==1 && p[(i+1)/2]==1) a[i] = 1;
    vi s(MAX+2);
    rep1(i, MAX) s[i+1] = s[i] + a[i];
    rep(i, q) cout << (s[r[i]+1]-s[l[i]]) << endl;
    return 0;
}
