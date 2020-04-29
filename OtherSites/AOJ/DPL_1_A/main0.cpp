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

#define INF (1e5)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const int m_max = 20;
vi c(m_max);
int change(int n, int v) {
    if (n == 0) return 0;
    int cnt = INF;
    rep1r(i, v) {
        int p = change(n, i-1);
        if (p == -1) continue;
        cnt = min(cnt, p);
    }
    int r = n / c[v];
    n -= r * c[v];
    r += change(n, v-1);
    cnt = min(cnt, r);
    return cnt;
}

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) cin >> c[i];
    sort(c.begin(), c.begin()+m);
    cout << change(n, m-1) << endl;
    return 0;
}
