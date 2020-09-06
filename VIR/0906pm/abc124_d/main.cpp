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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char, int>> cnt;
    cnt.emplace_back('1', 0);
    rep(i, n) {
        if (s[i] != cnt.back().first) cnt.emplace_back(s[i], 0);
        cnt.back().second++;
    }
    if (cnt.back().first == '0') cnt.emplace_back('1', 0);
    int l = 0, r = 0, ans = 0, len = 0, sum = 0;
    while (l<sz(cnt) && r<sz(cnt)) {
        while (len<k || (len==k&&cnt[r-1].first=='0')) {
            ++r;
            sum += cnt[r-1].second;
            if (r >= sz(cnt)) break;
            if (cnt[r-1].first == '0') ++len;
        }
        ans = max(ans, sum);
        if (l >= sz(cnt)) break;
        ++l; sum -= cnt[l-1].second;
        ++l; sum -= cnt[l-1].second;
        --len;
    }
    cout << ans << endl;
    return 0;
}
