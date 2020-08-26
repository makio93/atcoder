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

vector<vi> b, c;
int search(int d, vector<vi> a) {
    if (d == 9) {
        int score = 0;
        rep(i, 3) rep(j, 3) {
            if (i<=1) if (a[i][j]==a[i+1][j]) score += b[i][j];
            if (j<=1) if (a[i][j]==a[i][j+1]) score += c[i][j];
        }
        return score;
    }
    int score = (d%2==0?0:INF);
    rep(i, 3) rep(j, 3) if (a[i][j] == -1) {
        a[i][j] = d%2;
        if (d%2==0) score = max(score, search(d+1, a));
        else score = min(score, search(d+1, a));
        a[i][j] = -1;
    }
    return score;
}

int main(){
    b = vector<vi>(2, vi(3)); c = vector<vi>(3, vi(2));
    rep(i, 2) rep(j, 3) cin >> b[i][j];
    rep(i, 3) rep(j, 2) cin >> c[i][j];
    int sum = 0;
    rep(i, 2) rep(j, 3) sum += b[i][j];
    rep(i, 3) rep(j, 2) sum += c[i][j];
    int ans = search(0, vector<vi>(3, vi(3, -1)));
    cout << ans << endl;
    cout << (sum - ans) << endl;
    return 0;
}
