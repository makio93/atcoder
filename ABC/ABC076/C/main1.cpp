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

string s, t;

bool match(int k) {
    rep(i, sz(t)) {
        if (s[k+i]!=t[i]&&s[k+i]!='?') {
            return false;
        }
    }
    return true;
}

string construct(int k) {
    string res = s;
    rep(i, sz(t)) {
        res[k+i] = t[i];
    }
    rep(i, sz(res)) {
        if (res[i] == '?') res[i] = 'a';
    }
    return res;
}

int main(){
    cin >> s >> t;
    string ans = {'z' + 1 };
    bool exist = false;
    rep(i, sz(s)-sz(t)+1) {
        bool ok = match(i);
        if (ok) {
            ans = min(ans, construct(i));
            exist = true;
        }
    }
    if (exist) cout << ans << endl;
    else puts("UNRESTORABLE");
    return 0;
}
