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
    int n;
    cin >> n;
    vs a(n);
    rep(i, n) cin >> a[i];
    vector<map<char, bool>> cnt(n);
    rep(i, n) rep(j, n) cnt[i][a[i][j]] = true;
    deque<char> s;
    int up = n / 2, down = (n - 1) / 2;
    while (up < n) {
        bool ok = false;
        for (char c='a'; c<='z'; ++c) {
            if (cnt[up][c] && cnt[down][c]) {
                s.pb(c);
                if (up != down) s.push_front(c);
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << endl;
            return 0;
        }
        ++up; --down;
    }
    rep(i, sz(s)) cout << s[i];
    cout << endl;
    return 0;
}
