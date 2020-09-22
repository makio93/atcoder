#include <bits/stdc++.h>
using namespace std;

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

// 解説PDFの別解より：ランレングス圧縮っぽく集計してから数える解法

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char, int>> term, term2;
    rep(i, n) {
        if (term.empty() || term.back().first!=s[i]) term.emplace_back(s[i], 0);
        term.back().second++;
    }
    rep(i, sz(term)) {
        if (i%2==1 && k>0) {
            term[i].first = term[i-1].first;
            --k;
        }
        if (!term2.empty() && term2.back().first==term[i].first) term2.back().second += term[i].second;
        else term2.emplace_back(term[i].first, term[i].second);
    }
    int ans = 0;
    rep(i, sz(term2)) {
        ans += term2[i].second - 1;
    }
    cout << ans << endl;
    return 0;
}
