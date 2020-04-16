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
    string s;
    cin >> s;
    vector<map<char, int>> mp(n);
    rep1(i, n-1) {
        rep(j, i) mp[j][s[i]]++;
    }
    ll ans = 0;
    rep(i, n-2) for (int j=i+1; j<n-1; ++j) {
        if (s[i]==s[j]) continue;
        char k;
        if (s[i]!='R'&&s[j]!='R') k = 'R';
        if (s[i]!='G'&&s[j]!='G') k = 'G';
        if (s[i]!='B'&&s[j]!='B') k = 'B';
        ans += mp[j][k];
        if (i+2*(j-i)<n) {
            if (s[i+2*(j-i)]==k) --ans;
        }
    }
    cout << ans << endl;
    return 0;
}
