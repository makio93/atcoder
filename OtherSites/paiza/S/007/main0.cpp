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

string s;
vll dfs(int p, int& d) {
    vll cnt(26);
    if (isalpha(s.c_str()[p])) {
        cnt[(int)s[p]-'a']++;
        ++d;
    }
    else if (s[p] == '(') {
        ++p; ++d;
        while (s[p] != ')') {
            int di = 0;
            vll tcnt = dfs(p, di);
            rep(i, 26) cnt[i] += tcnt[i];
            d += di; p += di;
        }
        ++d;
    }
    else if (isdigit(s.c_str()[p])) {
        int l = 0;
        while (isdigit(s.c_str()[p+l])) ++l;
        ll mul = stoll(s.substr(p, l));
        p += l; d += l;
        int di = 0;
        vll tcnt(dfs(p, di));
        rep(i, 26) cnt[i] += tcnt[i] * mul;
        d += di; p += di;
    }
    return cnt;
}

int main(){
    s = '(';
    string t;
    cin >> t;
    s += (t + ')');
    int di = 0;
    vll ans = dfs(0, di);
    rep(i, 26) printf("%c %lld\n", (char)(i+'a'), ans[i]);
    return 0;
}
