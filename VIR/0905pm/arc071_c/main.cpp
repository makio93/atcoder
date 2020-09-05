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

const string YES = "YES";
const string NO = "NO";

int main(){
    string s, t;
    cin >> s >> t;
    int sn = sz(s), tn = sz(t);
    vector<vi> sums(2, vi(sn+1)), sumt(2, vi(tn+1));
    rep(i, sn) {
        sums[0][i+1] = sums[0][i] + (s[i]=='A'?1:0);
        sums[1][i+1] = sums[1][i] + (s[i]=='B'?1:0);
    }
    rep(i, tn) {
        sumt[0][i+1] = sumt[0][i] + (t[i]=='A'?1:0);
        sumt[1][i+1] = sumt[1][i] + (t[i]=='B'?1:0);
    }
    int q;
    cin >> q;
    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        int snum = (sums[0][b+1]-sums[0][a])%3+(3-(sums[1][b+1]-sums[1][a])%3+3)%3;
        int tnum = (sumt[0][d+1]-sumt[0][c])%3+(3-(sumt[1][d+1]-sumt[1][c])%3+3)%3;
        if (snum%3==tnum%3) cout << YES << endl;
        else cout << NO << endl;
    }
    return 0;
}
