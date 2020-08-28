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

// 解説AC：再帰関数によりメモ化再帰を実装

string s;
int n;
vector<vi> dp;
int search(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (r-l < 3) return (dp[l][r] = 0);
    int res = dp[l][r];
    for (ll k=l+1; k<r; ++k) {
        res = max(res, search(l,k)+search(k,r));
        if (s[l]=='i'&&s[k]=='w'&&s[r-1]=='i') {
            if (search(l+1,k)==k-l-1 && search(k+1,r-1)==r-k-2) res = max(res, r-l);
        }
    }
    return (dp[l][r] = res);
}

int main(){
    cin >> s;
    n = sz(s);
    dp = vector<vi>(n+1, vi(n+1, -1));
    cout << (search(0,n)/3) << endl;
    return 0;
}
