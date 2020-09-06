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


ll dfs(int n, ll x) {
    if (n == 0) return 1LL;
    ll res = 0;
    ll len = (1LL<<(n+2)) - 3, hnum = (1LL<<n) - 1; 
    if (x >= len-1) res += hnum * 2 + 1;
    else if (x >= (len-3)/2+3) {
        res += hnum + 1;
        res += dfs(n-1, x-1-(len-3)/2-1);
    }
    else if (x >= (len-3)/2+2) res += hnum + 1;
    else if (x >= (len-3)/2+1) res += hnum;
    else if (x >= 2) res += dfs(n-1, x-1);
    return res;
}

int main(){
    int n;
    ll x;
    cin >> n >> x;
    cout << dfs(n, x) << endl;
    return 0;
}
